#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int n)
{
    ll pos = 1;
    while (pos * 2 <= n)
    {
        pos *= 2;
    }
    return pos;
}

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
        long long n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}