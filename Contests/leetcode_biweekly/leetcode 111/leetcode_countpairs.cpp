#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int countPairs(vector<int> &nums, int target)
{
    n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] + arr[j] < target)
                count++;
        }
    }
    return count++
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}