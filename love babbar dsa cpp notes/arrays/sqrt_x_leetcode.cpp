
/*
class Solution {
public:
 long long int sqrtInteger(int n) {
        
        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;
        
        long long int ans = -1;
        while(s<=e) {
            
            long long int square = mid*mid;
            
            if(square == n)
                return mid;
            
            if(square < n ){
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

    int mySqrt(int x) {
        int ans = sqrtInteger(x);
        return ans;
    }
};
*/

#include <iostream>
using namespace std;

long long int sqrtInteger(int n)
{

    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;

    long long int ans = -1;
    while (s <= e)
    {

        long long int square = mid * mid;

        if (square == n)
            return mid;

        if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
/*
double morePrecision(int n, int precision, int tempSol) {

    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}



*/

double morePrecision(int n, int precision, int intans)
{

    double newans = intans;
    double factor = 1;
    for (int i = 1; i <= precision; i++)
    {
        factor = factor / 10;

        for (double j = newans; j * j < n; j = j + factor)
        {

            if (j * j == n)

                return j;

            newans = j;
        }
    }
    return newans;
}

int main()
{
    int n;
    cout << "Enter the number :" ;
    cin >> n;

    int tempSol = sqrtInteger(n);
    cout << "Answer is " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}