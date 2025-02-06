#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int ops)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, maxFreq = 0;
        ll total = 0;

        while (r < nums.size())
        {
            total += nums[r];
            while ((r - l + 1) * nums[r] - total > k + ops)
            {
                total -= nums[l];
                l++;
            }
            maxFreq = max(maxFreq, r - l + 1);
            r++;
        }

        return min(maxFreq, (int)nums.size());
    }
};

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
        Solution sol;
        int n, k, ops;
        cin >> n >> k >> ops;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cout << sol.maxFrequency(nums, k, ops) << endl;
    }
    return 0;
}