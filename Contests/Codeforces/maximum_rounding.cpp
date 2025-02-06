#include <iostream>
#include <vector>

using namespace std;

string maximizeRounding(string x)
{
    int n = x.length();
    int ind = n - 1;
    int pos = ind + 1;

    while (ind > -1){
        if (x[ind] - '0' >= 5)
        {
            while (ind > -1 && x[ind] == '9')
            {
                ind--;
            }
            if (ind == -1)
            {
                x = '1' + x;
                pos = 1;
                break;
            } 
         else{
            pos = ind + 1;
            int c = x[ind] - '0';
            c++;
            x[ind] = (char)(c + '0');
            }
        }
        else
            ind--;
    }
    for (int i = pos; i < size(x); i++)
    {
        x[i] = '0';
    }

    return x;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string x;
        cin >> x;

        string result = maximizeRounding(x);
        cout << result << endl;
    }

    return 0;
}

//pos = ind + 1;
// x[ind] = ( x[ind] - '0' ) + 1 ; would not work why ??