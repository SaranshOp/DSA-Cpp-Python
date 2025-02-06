#include <iostream>
using namespace std;
#include <cstring> // Include the cstring header for strlen
int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    cout << arr << endl;
    // attention here
    cout << ch << endl;

    char *c = &ch[0];
    // prints entire string
    cout << c << endl;

    char temp = 'z';
    char *p = &temp;

    cout << p << endl;

    char temp2[] = "zebra\0ok\0-"; // Use char array for strings
    char *q = temp2;              // Use a pointer to char to point to the array 'temp'

    cout << q << endl; // This will print the string "zebra"

    char *currentString = temp2; // Start with the first string

    while (*currentString != '\0') // Iterate through the strings
    {
        cout << currentString << endl;              // Print the current string
        currentString += strlen(currentString) + 1;
        cout << "new ->" << currentString << endl;  // Move to the next string
    }

    return 0;
}