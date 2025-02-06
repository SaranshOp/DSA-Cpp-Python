#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();

    vector<long long> ans;
    set<int> unmarked;
    for (int i = 0; i < n; i++)
    {
        unmarked.insert(i);
    }

    for (auto q : queries)
    {
        int j = q[0];
        int k = q[1];

        if (unmarked.count(j))
            unmarked.erase(j);
        vector<pair<int, int>> poparray;
        for (auto i : unmarked)
        {
            poparray.push_back({nums[i], i});
        }
        sort(poparray.begin(), poparray.end());

        for (auto p = 0; p < k && p < poparray.size(); p++)
        {
            unmarked.erase(poparray[p].second);
        }
        long long sum = 0;
        for (auto i : unmarked)
            sum += nums[i];
        //
        ans.push_back(sum);
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
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<vector<int>> queries(m, vector<int>(2));
        for (int i = 0; i < m; i++)
        {
            cin >> queries[i][0] >> queries[i][1];
        }
        vector<long long> result = unmarkedSumArray(nums, queries);
        for (long long res : result)
        {
            cout << res << " ";
        }
        cout << "\n";
    }
    return 0;
}
