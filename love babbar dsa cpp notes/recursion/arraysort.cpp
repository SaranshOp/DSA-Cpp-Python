#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size)
{

    // base case
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
        return false;
    else
        return isSorted(arr + 1, size - 1);
}

int main()
{

    int arr[] = {2, 4, 9, 9, 9, 12, 40};
    int size = sizeof(arr) / sizeof(int);

    bool ans = isSorted(arr, size);

    if (ans)
    {
        cout << "Array is sorted " << endl;
    }
    else
    {
        cout << "Array is not sorted " << endl;
    }

    return 0;
}