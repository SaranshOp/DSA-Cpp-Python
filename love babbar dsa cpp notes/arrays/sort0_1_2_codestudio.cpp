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

void sort012(int *arr, int n)
{
   int i = 0 , j = 0, k = n-1;

   // i(low) for 0 j(mid) for 1 and k(high) for 2
   
   for(; j<=k ;){

      if (arr[j] == 1)
      j++;

      else if (arr[j] == 0){
      swap( arr[j++] , arr[i++] );
      }

      else if (arr[j] == 2){
      swap(arr[j], arr[k--]);
      }
   }

}

int main(){
    int array[] = 


//     Sample Input 1 :
// 2
// 6
// 0 1 2 2 1 0
// 7
// 0 1 2 1 2 1 2
//      Sample Output 1 :
// 0 0 1 1 2 2
// 0 1 1 1 2 2 2

//      Sample Input 2 :
// 2
// 7
// 2 2 2 1 1 1 0
// 6
// 2 1 2 0 1 0
//      Sample Output 2 :
// 0 1 1 1 2 2 2
// 0 0 1 1 2 2


    return 0;
}
 