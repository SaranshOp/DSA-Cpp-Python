#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll subseq(vector<int> &nums, bool onlyadd, int idx, vector<vector<ll>> &dp)
{
    if (idx == 0)
        onlyadd = true;
    if (idx > nums.size() - 1)
        return 0;
    ll a = 0, b = 0;

    if (dp[idx][onlyadd] != -1)
        return dp[idx][onlyadd];

    a = nums[idx] + subseq(nums, false, idx + 1, dp); // add
    if (!onlyadd)
    {
        b = subseq(nums, true, idx + 1, dp) - nums[idx];
        a = max(a, b);
    }

    return dp[idx][onlyadd] = a;
}
long long maximumTotalCost(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<ll>> dp(n + 3, vector<ll>(2, -1));
    return subseq(nums, false, 0, dp);
}

int main()
{
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    // cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)r − l

    vector<int> nums = {1, -2, 3, 4};
    cout << maximumTotalCost(nums) << endl;

    vector<int> nums1 = {1, -1, 1, -1};
    cout << maximumTotalCost(nums1) << endl;

    vector<int> nums2 = {0};
    cout << maximumTotalCost(nums2) << endl;

    vector<int> nums3 = {-937};
    cout << maximumTotalCost(nums3) << endl;
    // TC: O(2^n)
    return 0;
}
