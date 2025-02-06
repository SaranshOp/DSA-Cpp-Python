void reverseArray(int arr[], int n)
{
    // Reversing elements from index 0 to n-1
    reverse(arr, arr + n);
}
int main()
{
    int n = 5;
    int arr[] = {5, 4, 3, 2, 1};
    reverseArray(arr, n);
    printArray(arr, n);
    return 0;
}

/// arr + n is the address of the last element of the array. but how ??
//  arr is the address of the first element of the array.
//  arr + 1 is the address of the second element of the array.
// but how
//  arr + 1 = arr + 1 * sizeof(int) = arr + 1 * 4 = arr + 4