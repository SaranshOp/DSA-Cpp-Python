#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    cout << "x ";
    for (int i = 0; i < n; i++)
    {
        cout << "x ";
        for (int j = i + 1; j < n; j++)
        {
            cout << "x ";
            for (int k = j + 1; k < n; k++)
            {
                cout << i <<" "<< j <<" "<< k << endl;
            }
            //cout << "x \n";
        }
        //cout << "x \n";
    }
    //cout << "x \n";
}