#include <iostream>
#include "L8.h"
using namespace std ;


int min_array(int arr[], size)
{
    int mini = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (mini > arr[i])
            mini = min(mini, arr[i])
    } cout << "min of array " << mini << endl ;
    return mini ;
}

int max_array(int arr[], size)
{
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (maxi < arr[i])
            maxi = max(maxi, arr[i])
    }
    cout << "max of array " << maxi << endl ;
    return maxi ;
}
void update(){

}
void insertarray();
void printarray();
int main()
{   
    int size;
    int array[10000];
    cout << "enter arry size and then elements :" ;
    cin >> size ;
    insertarray(array , size);
    printarray(array , size);

    max_array(array, size);
    min_array(array, size);
}