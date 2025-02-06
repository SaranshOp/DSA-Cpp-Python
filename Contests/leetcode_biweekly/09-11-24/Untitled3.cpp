#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int ans = -1;
        int r = nums.size();
        int l = 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (hasValidSubarray(mid, nums, k))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            cout << "ans: " << ans << endl;
        }
        return ans;
    }

private:
    bool hasValidSubarray(int windowSize, vector<int> &nums, int targetSum)
    {

        int bitcntarr[32] = {0}; // sets only one ele to zero rest all are by default 0;
        int r = 0, l = 0, number = 0;
        while (r < nums.size())
        {

            int numb = nums[r];
            for (int i = 0; i < 32; i++)
                cout << bitcntarr[i] << " ";
            cout << endl;
            while (r - l + 1 > windowSize)
            {
                cout << "negating: " << nums[l] << endl;
                updateBcount(nums[l], bitcntarr, -1);
                l++;
            }
            for (int i = 0; i < 32; i++)
                cout << bitcntarr[i] << " ";
            cout << endl;
            updateBcount(numb, bitcntarr, 1);
            if (r - l + 1 == windowSize)
            {
                for (int i = 0; i < 32; i++)
                    cout << bitcntarr[i] << " ";
                cout << endl;
                number = bitcntarrtonumb(bitcntarr);
                cout << "number: " << number << endl;
                if (number >= targetSum)
                    return true;
            }

            r++;
        }
        return false;
    }
    void updateBcount(int numb, int *bitcntarr, int delta)
    {
        for (int i = 0; i < 32; i++)
        {
            if (((numb >> i) & 1) != 0)
                bitcntarr[i] += delta;
        }
    }
    int bitcntarrtonumb(int bitcntarr[])
    {
        int number = 0;
        // Convert the bit count array to a number.
        for (int i = 0; i < 32; ++i)
        {
            number += (bitcntarr[i] != 0) * (1 << i); // turning the bit counts into a number
        }
        return number;
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
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution s;
        cout << s.minimumSubarrayLength(nums, k) << endl;
    }
    return 0;
}