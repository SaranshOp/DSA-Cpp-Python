#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> x(n - 1);
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> x[i];
        }

        // Find the maximum value in x
        int max_x = *max_element(x.begin(), x.end());

        vector<ll> a(n);
        // Set the starting number to be larger than max_x
        a[0] = max_x + 1;

        // Calculate a2 through an based on the given conditions
        for (int i = 1; i < n; ++i)
        {
            a[i] = x[i - 1] + a[i - 1];
        }

        // Output the array a for this test case
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
