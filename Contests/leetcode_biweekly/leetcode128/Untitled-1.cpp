#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// struct FirstAscending {
//     bool operator()(const vector<int>& a, const vector<int>& b) const {
//         return a[0] < b[0];
//     }
// };

int minRectanglesToCoverPoints(vector<vector<int>> &points, int w)
{
    int i = 0, n = points.size(), c = 0;
    sort(points.begin(), points.end());

    while (i < n)
    {
        int k = points[i][0];
        while (i < n - 1)
        {
            if (points[i + 1][0] - k <= w)
                i++;
            else
                break;
        }
        c++;
        i++;
        if ((i == n - 1) && (points[i][0] - k > w))
        {
            c++;
            return c;
        }
    }
    return c;
}

int main()
{
    vector<vector<int>> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}};
    int w = 2;
    cout << minRectanglesToCoverPoints(points, w) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int minRectanglesToCoverPoints(vector<vector<int>> &points, int w)
{

    int i = 0, n = points.size(), c = 0;

    sort(points.begin(), points.end(), firstascending());

    while (i < n)
    {
        int k = points[i].first;
        while (i < n - 1)
        {
            if (points[i + 1].first - k <= w)
                i++;
            else
                break;
        }
        c++;
        i++;
        if ((i == n - 1) && points[i] - k > w)
        {
            c++;
            return c;
        }
    }
}

int main()
{
    vector<vector<int>> points = {[0, 0], [ 1, 1 ], [ 2, 2 ], [ 3, 3 ], [ 4, 4 ], [ 5, 5 ], [ 6, 6 ]};
    int w = 2;
    cout < < < < endl;
    return 0;
}