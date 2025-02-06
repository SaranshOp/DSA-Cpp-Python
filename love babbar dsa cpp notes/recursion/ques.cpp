#include <bits/stdc++.h>
using namespace std;

// char reversedarray( char *a ){
// a = a + 1;
// return reversedarray( a );
// cout << a[0] << " " ;
// }

void reversedarray(char *a) {
    if (*a == '\0') {
        return; // Base case: end of string
    }
    
    reversedarray(a + 1); // Recursive call
    
    cout << *a; // Print the current character
}

int main() {
    char array[] = "saransh";
    cout << "reversed: ";
    reversedarray(array);
    cout << endl;
    
    return 0;
}