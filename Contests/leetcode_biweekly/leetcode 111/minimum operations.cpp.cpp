class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> array;
        int cnt = 0;
        array.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            auto lo = lower_bound(array.begin(), array.end(), nums[i]);
            auto up = upper_bound(array.begin(), array.end(), nums[i]);
            if (up == array.end())
                array.push_back(nums[i]);
            else
            {
                int j = up - array.begin();
                array[j] = min(array[j], nums[i]);
                cnt++;
            }
        }
        return cnt;
    }
};