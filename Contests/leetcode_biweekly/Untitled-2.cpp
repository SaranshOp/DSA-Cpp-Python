#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, vector<string> &a)
{
    vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));
    vector<vector<string>> str(2, vector<string>(n + 1, ""));
    dp[0][0] = 1;
    str[0][0] = "";
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i > 0 && (str[i - 1][j] + a[i][j] < str[i][j - 1] + a[i][j] || str[i][j - 1].empty()))
            {
                dp[i][j] = dp[i - 1][j];
                str[i][j] = str[i - 1][j] + a[i][j];
            }
            else if (j > 0 && (str[i][j - 1] + a[i][j] < str[i - 1][j] + a[i][j] || str[i - 1][j].empty()))
            {
                dp[i][j] = dp[i][j - 1];
                str[i][j] = str[i][j - 1] + a[i][j];
            }
            else if (i > 0 && j > 0 && str[i - 1][j] + a[i][j] == str[i][j - 1] + a[i][j])
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                str[i][j] = min(str[i - 1][j], str[i][j - 1]) + a[i][j];
            }
        }
    }
    cout << str[1][n - 1] << "\n" << dp[1][n - 1] << "\n";
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
        int n;
        cin >> n;
        vector<string> a(2);
        cin >> a[0] >> a[1];
        solve(n, a);
    }
    return 0;
}