#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // largest word in a sentence
    int n;
    cin >> n;
    cin.ignore();

    char arr[n];
    cin.getline(arr, n);
    cin.ignore();

    int i = 0;
    int currLen = 0, maxLen = 0;
    while (i < n)
    {
        if (arr[i] == '\0') break;
        if (arr[i] == ' ')
        {
            if (currLen > maxLen)
                maxLen = currLen;
            currLen = 0;
        }
        else
            currLen++;
         std::cout << "crr " << currLen << endl;
        i++;
    }
    // std::cout << "crr " << currLen <<" max " << maxLen << std::endl;
    if (currLen > maxLen)
        maxLen = currLen;
    cout << "max length of words in arr :" << maxLen << endl;
    return 0;
}
