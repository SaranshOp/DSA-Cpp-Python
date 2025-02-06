#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
{
    vector<int> ans;
    for (auto i = 0; i < nums.size(); i++)
    {
        for (auto j = 0; j <= i - indexDifference; j++)
        {
            if (abs(nums[i] - nums[j]) >= valueDifference && abs(i - j) >= indexDifference)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    if (ans.empty())
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input. txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        void solve();
    }
    return 0;
}
