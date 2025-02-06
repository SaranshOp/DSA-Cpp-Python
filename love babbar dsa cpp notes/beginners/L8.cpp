#include <iostream>
using namespace std;
// shift + alf + f = format ;
// arr[] = { 0..... n = 1} ; all 0 to n array elements initialized 
void insertarray(int arr[], int size) {
    int i = 0;
    while (i < size) {
        int x;
        cin >> x;
        arr[i] = x;
        i++;
    }
}

void printarray(int arr[], int size) {
    int i = 0;
    while (i < size) {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
}

int main() {
    int MAX;
    cout << "enter the sixe of array : " ;
    cin >> MAX;
    int number[MAX];

 cout << "inserting array elements : " ;
    insertarray(number, MAX);
    printarray(number, MAX);

 cout << "here is an pre generated one \n" ;
    int n = 3;
    int second[n] = {5, 4, 3};
    int i = 0;
    while (i < n) {
        cout << second[i] << " ";
        i++;
    }

    cout << "\neverything is fine \nexitiiiing" << endl;
}


