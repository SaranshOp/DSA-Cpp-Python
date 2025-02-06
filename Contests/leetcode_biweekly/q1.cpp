#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findLastVisitedIntegers(vector<string>& words) {
    vector<int> nums, rev_num;
    vector<int> lastints;
    int consecutive_prev = 0;

    for (string element : words) {
        if (element == "prev") {
            if (consecutive_prev >= nums.size()) {
                lastints.push_back(-1);
            } else {
                lastints.push_back(rev_num[consecutive_prev]);
            }
            consecutive_prev++;
        } else {
            int num = stoi(element);
            nums.push_back(num);
            rev_num = nums;
            reverse(rev_num.begin(), rev_num.end());
            consecutive_prev = 0;
        }
    }

    return lastints;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    vector<int> lastints = findLastVisitedIntegers(words);
    for (int i = 0; i < n; i++) {
        cout << lastints[i] << " ";
    }
    cout << endl;

    return 0;
}