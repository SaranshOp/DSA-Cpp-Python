#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

const int MAX_N = 200000; // Define the maximum size

int n;
string row1, row2;
bool visited[2][MAX_N]; // 2 rows, MAX_N columns

int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Possible movement directions (down, up, right, left)

// Depth-first search function
void dfs(int x, int y)
{
    stack<pair<int, int>> s;
    s.push({x, y});
    visited[x][y] = true;

    while (!s.empty())
    {
        auto [cur_x, cur_y] = s.top();
        s.pop();

        for (auto dir : directions)
        {
            int new_x = cur_x + dir[0];
            int new_y = cur_y + dir[1];

            if (new_x >= 0 && new_x < 2 && new_y >= 0 && new_y < n && !visited[new_x][new_y] &&
                ((new_x == 0 && row1[new_y] == '0') || (new_x == 1 && row2[new_y] == '0')))
            {
                visited[new_x][new_y] = true;
                s.push({new_x, new_y});
            }
        }
    }
}

// Function to count the number of connected plots
int countPlots()
{
    memset(visited, false, sizeof(visited)); // Reset the visited array
    int plot_count = 0;

    // Loop through both rows and run DFS to find plots
    for (int i = 0; i < n; i++)
    {
        if (!visited[0][i] && row1[i] == '0')
        {
            dfs(0, i);
            plot_count++;
        }
        if (!visited[1][i] && row2[i] == '0')
        {
            dfs(1, i);
            plot_count++;
        }
    }

    return plot_count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;            // Read the length of rows
    cin >> row1 >> row2; // Read the two rows

    int initial_plots = countPlots(); // Count the initial plots
    int critical_count = 0;

    // Check each cell in row1 and row2
    for (int i = 0; i < n; i++)
    {
        if (row1[i] == '0')
        {
            row1[i] = 'X'; // Simulate infection
            int new_plots = countPlots();
            if (new_plots == 3)          {
                critical_count++;
            }
            row1[i] = '0'; // Restore the original state
        }

        if (row2[i] == '0')
        {
            row2[i] = 'X'; // Simulate infection
            int new_plots = countPlots();
            if (new_plots == 3)
            {
                critical_count++;
            }
            row2[i] = '0'; // Restore the original state
        }
    }

    cout << critical_count << endl; // Output the critical count

    return 0;
}
