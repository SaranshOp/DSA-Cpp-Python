#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int solve(std::vector<int> &rew, int x, int ind, vector<vector<int>> &dp)
{
    cout << ind << " " << x << endl;
    if (ind >= rew.size())
    {
        return x;
        return x;
    }
    if (dp[ind][x] != -1)
    {
        return dp[ind][x];
    }
    int option1 = solve(rew, x, ind + 1, dp);
    int option2 = 0;
    if (rew[ind] > x)
    {
        option2 = solve(rew, x + rew[ind], ind + 1, dp);
    }
    cout << ind << " " << x << " " << option1 << " " << option2 << endl;
    return dp[ind][x] = max(option1, option2);
}

int maxReward(std::vector<int> &rewValues)
{
    int n = rewValues.size();
    vector<vector<int>> dp(2001, vector<int>(4001, -1));
    sort(rewValues.begin(), rewValues.end());
    return solve(rewValues, 0, 0, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> rewValues = {1, 6, 4, 3, 2};
    cout << maxReward(rewValues) << endl;

    return 0;
}
