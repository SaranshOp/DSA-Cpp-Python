#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001][501][501]; // DP table to memoize results

int solve(int i, int remX, int remY, vector<int> &H)
{
    // cout << "i: " << i << " remX: " << remX << " remY: " << remY << endl;
    // cout << "dp[i][remX][remY]: " << dp[i][remX][remY] << endl;
    // Base case: No more cars to process
    if (i == H.size())
        return 0;

    // Memoization check
    if (dp[i][remX][remY] != -1)
        return dp[i][remX][remY];

    int res = 0;

    // Option 1: Assign car i to line X if there's enough time
    if (remX >= H[i])
    {
        res = max(res, 1 + solve(i + 1, remX - H[i], remY, H));
    }

    // Option 2: Assign car i to line Y if there's enough time
    if (remY >= H[i])
    {
        res = max(res, 1 + solve(i + 1, remX, remY - H[i], H));
    }

    // Option 3: Skip the current car -  IF YOU ARE NOT SORTING CAN USE THIS ONE
    // res = max(res, solve(i + 1, remX, remY, H));

    // cout << "res: " << res << endl;
    dp[i][remX][remY] = res;
    return res;
}

int solution(vector<int> &H, int X, int Y)
{
    sort(H.begin(), H.end());
    // for (int i = 0; i < H.size(); i++)
    // {
    //     cout << H[i] << " ";
    // }
    memset(dp, -1, sizeof(dp)); // Initialize the memoization table with -1
    return solve(0, X, Y, H);   // Start with car 0, full X and Y hours remaining
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
        int N, X, Y;
        cin >> N >> X >> Y;
        vector<int> H(N);
        for (int i = 0; i < N; i++)
        {
            cin >> H[i];
        }
        cout << endl;
        // cout << X << " " << Y << endl;
        cout << solution(H, X, Y) << endl;
    }
    return 0;
}

// 3
// 3 1 1
// 1 1 1
// 5 8 9
// 6 5 5 4 3
// 5 17 5
// 6 5 2 1 8
// // Output
// 2

// 4

// 5
