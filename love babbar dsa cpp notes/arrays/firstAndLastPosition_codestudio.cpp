#include <bits/stdc++.h> 
using namespace std;

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int key = k;
    int start = 0, end = n - 1;
    vector<int> ans(2, -1); // Initialize ans with -1 for cases where the element is not found.

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] < k) {
            start = mid + 1;
        } else if (arr[mid] > k) {
            end = mid - 1;
        } else {
            // Found the target element at index mid.
            ans[0] = mid;
            ans[1] = mid;

            // Search for the first occurrence of the target element towards the left.
            for (int i = mid - 1; i >= 0 && arr[i] == k; i--) {
                ans[0] = i;
            }

            // Search for the last occurrence of the target element towards the right.
            for (int i = mid + 1; i < n && arr[i] == k; i++) {
                ans[1] = i;
            }

            break;
        }
    }

    return make_pair(ans[0], ans[1]);
}

/* another one that is my own //

#include <bits/stdc++.h> 
using namespace std;

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int key = k;
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    vector<int> ans(2, -1);

    while (start <= end) {
        if (arr[mid] < k) {
            start = mid + 1;
        } else if (arr[mid] > k) {
            end = mid - 1;
        } else if (arr[mid] == k) {
            ans[0] = mid;
            ans[1] = mid;

            for (int i = mid - 1; i >= 0; i--) {
                if (arr[i] != k) {
                    ans[0] = i + 1;
                    break;
                }
                ans[0] = i;
            }

            for (int i = mid + 1; i < n; i++) {
                if (arr[i] != k) {
                    ans[1] = i - 1;
                    break;
                }
                ans[1] = i; 
            }

            break;
        }
        mid = start + (end - start) / 2;
    }

    return make_pair(ans[0], ans[1]);
}
*/

/* love abbrr functions methad :
#include<vector>
using namespace std;
int firstOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    
    return p;
}
*/