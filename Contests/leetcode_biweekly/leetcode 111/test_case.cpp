#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    // cout << "mid a first bst "<< mid << nums[mid] << " \n" ;
    while (s < e)
    {
        //{4,5,6,7,0,1,2}
        if (nums[mid] > nums[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
        // cout << "mid after every bst "<< mid << nums[mid] << " \n" ;
    }
    cout << "s  e " << s << "" << e << " \n";
    int lowerpivot = mid;
    cout << "lowerpivot " << lowerpivot << " \n";
    //{4,5,6,7,0,1,2}
    if (nums[0] < target && target <= nums[mid - 1])
    {
        e = lowerpivot - 1;
        s = 0;
    }
    else
    {
        s = lowerpivot;
        e = n - 1;
    }
    cout << "s  e " << s << "" << e << " \n";
    mid = s + (e - s) / 2;
    cout << "mid a first " << mid << nums[mid] << " \n";
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] < target)
        {
            s = mid + 1;
        }

        if (nums[mid] > target)
        {
            e = mid - 1;
        }
        cout << "s  e " << s << "" << e << " \n";
        mid = s + (e - s) / 2;
        cout << "new mid " << mid << nums[mid] << " \n";
    }
    return -1;
};

int main()
{
    // cout << " \n" ;
    vector<int> arr = {1,3};
    int t = 3;
    int ouut = search(arr, t);
    cout << ouut << " \n";
    return 0;
}