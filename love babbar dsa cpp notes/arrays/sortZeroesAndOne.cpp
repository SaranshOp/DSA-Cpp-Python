#include <iostream>
using namespace std;


void sortZeroesAndOne(int input[], int size) {

    int i=0 , j=size-1;
    
    while(i<j){
        
        if(input[i]==0){
        i++;
        }

        if(input[j]==1){
        j--;
        }

        if(input[i]==1 & input[j]==0 && i < j){
            input[i]=0;
            input[j]=1;
            i++;
            j--;
        }
        
    }

} int i=0 , j=size-1;
    
    while(i<j){
        
        if(input[i]==0){
        i++;
        }

        if(input[j]==1){
        j--;
        }

        if(input[i]==1 & input[j]==0 && i < j){
            input[i]=0;
            input[j]=1;
            i++;
            j--;
        }
        
    }

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

int main(){
    int array[] = { 1,1,0,0,0,0,1};

    return 0;
}

/* void sortZeroesAndOne(int *input, int size)
{
    int nextZero = 0;

    for (int i = 0; i < size; i++)
    {

        if (input[i] == 0)
        {
            int temp = input[nextZero];
            input[nextZero] = input[i];
            input[i] = temp;
            nextZero++;
        }
    }
} */