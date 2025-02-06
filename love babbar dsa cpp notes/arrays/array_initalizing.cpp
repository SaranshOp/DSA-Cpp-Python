#include <iostream>

using namespace std;

void printarray(int arr[], int n)
{
    int i = 0;
    cout << "printarray : { ";
    while (i < n)
    {
        cout << arr[i] << ", ";
        i++;
    }
    cout << "} " << endl;
}

void insertarray(int arr[], int size) {
    int i = 0;
    while (i < size) {
        int x;
        cin >> x;
        arr[i] = x;
        i++;
    }
}

int main(){
   
}