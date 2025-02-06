class Solution {
public:
    int search(vector<int>& nums, int target) {
    int n = nums.size();
    int s= 0, e = n-1;
    int mid = s + (e-s)/2;

while(s<e) {
if( nums[s] <= target ){
      if(nums[mid] >= nums[s]){
        if(nums[mid] >= target){
            e = mid;
        }
        else s = mid + 1;
        }
     else e = mid - 1;
 }
else {
   if(nums[mid] >= nums[s])
   s = mid + 1;
   else if(nums[mid] >= target){
            e = mid;
        }
        else s = mid + 1;
    }
mid = s + (e-s)/2;
}
if (nums[mid] == target )
return mid;  
return -1;
};
};
// runtime 0 sec this was BST with lots of bheja fry - all brute

// runtime 3 sec - this was very okay to understand 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int mid;

        while (s <= e) { // Changed the loop condition from 's < e' to 's <= e'.
            mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[s]) {
                if (target >= nums[s] && target < nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return -1;
    }
};

//  there is another way Love abbr did it by finding pivot forst ND then BST on a line(I or II)
// my code for it gave error - mine :
class Solution {
public:
    int search(vector<int>& nums, int target) {
    int n = nums.size();
    int s= 0, e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){

        if(nums[mid] >= nums[s]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
    mid = s + (e-s)/2;  
    }
    int lowerpivot = mid;
    if( nums[s] < target ){
    e = lowerpivot - 1; s = 0; 
    }
    else s = lowerpivot ; e = n -1 ;
    while(s<=e){
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] < target){
            e = mid - 1;
        }
        
        if(nums[mid] > target){
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
return -1;
};
};
// Babbr:
#include<vector>
using namespace std;

int getPivot(vector<int>& arr, int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    if( k >= arr[pivot] && k <= arr[n-1])
    {//BS on second line
        return binarySearch(arr, pivot, n-1, k);
    }
    else
    {//BS on first line
        return binarySearch(arr, 0, pivot - 1, k);
    }
    
}

