#include <iostream>
using namespace std;

void swaplast(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    cout << "swapped : success \n";
}

void swapalt(int arr[], int n)
{
    int st = 0;
    cout << "swapped alt: ";
    while (st < n-1)
    {
        swap(arr[st], arr[st+1]);
        st += 2;
    }
    cout << "success\n";
}


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

int main()
{

    //int arr[6] = {4, 1, -3, 2, 5};
    int arr[7] = {4, 1, -3, 2, 5, 2};
    int siz = sizeof(arr) / sizeof(int);
    printarray(arr, siz);
    cout << "size of array :" << siz << endl;

    swaplast(arr, siz);
    printarray(arr, siz);
    swapalt(arr , siz);
    printarray(arr, siz);
    return 0;
    
}