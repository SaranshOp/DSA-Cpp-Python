#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int minimumArea(vector<vector<int>> &grid)
{
    int x = 0, y = 0;
    int n = grid.size();
    int m = grid[0].size();
    int f = 0, minx = INT_MAX, miny = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (grid[i][j] == 1)
            {
                x = x < i ? i : x;
                y = y < j ? j : y;
                cout << x << " " << y << endl;
                minx = minx > i ? i : minx;
                miny = miny > j ? j : miny;
                cout << minx << " " << miny << endl;
            }
        }
    }
    return (x + 1 - minx) * (y + 1 - miny);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input. txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> grid = {{1, 0, 0, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0}};

    // cout << minimumArea(grid) << endl; // 12

    vector<vector<int>> grid2 = {{0, 1, 0},
                                 {1, 0, 1}};

    cout << minimumArea(grid2) << endl; // 6

    vector<vector<int>> grid1 = {{0, 0},
                                 {1, 0}};

    // cout << minimumArea(grid1) << endl; // 1

    // 1 <= grid.length, grid[i].length <= 1000 // TC: O(n*m)

    return 0;
}
