#include <bits/stdc++.h>
using namespace std;

#define mod 1000007
#define ll long long

// Function to find number of ordered
// positive integer pairs (x, y) such
// that they satisfy the equation
void solve(int n)
{
    // Initialize answer variable
    ll ans = 0;

    // Iterate over all possible values of y
    for (int y = n + 1; y <= n * n + n; y++)
    {
        // For valid x and y,
        // (n*n) % (y - n) has to be 0
        if ((n * n) % (y - n) == 0)
        {
            // Increment count of ordered pairs
            ans = (ans + 1) % mod;
        }
    }

    // Print the answer
    cout << ans << endl;
}

ll factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    ll fact = 1;
    for (unsigned int i = 1; i <= n; ++i)
    {
        fact = (fact * i) % mod;
    }
    return fact;
}

int main()
{
    int n = 3;
    ll fact = factorial(n);
    cout << fact << endl;
    solve(fact);
    return 0;
}
