#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

#include <set>
#include <string>

class Solution
{
public:
    bool isinSet(string c, set<string> &uni)
    {
        return uni.find(c) != uni.end(); // return 1 if already present
    }
    int maxUniqueSplit(string s)
    {
        set<string> uni;
        for (int i = 0; i < s.size(); i++)
        {
            string c = "";
            c += s[i];
            while (isinSet(c, uni) && i+1 < s.size())
            {
                i++;
                c += s[i];
            }
            cout << c << endl;
            uni.insert(c);
        }
        return uni.size();
    }

    // int maxUniqueSplitHelper(const string& s, int start, set<string>& unique,
    // int maxCount) {
    //     if (start == s.length()) {
    //         return unique.size();
    //     }

    //     for (int i = start + 1; i <= s.length(); i++) {
    //         string sub = s.substr(start, i - start);
    //         if (unique.find(sub) == unique.end()) {
    //             unique.insert(sub);
    //             maxCount = max(maxCount, maxUniqueSplitHelper(s, i, unique,
    //             maxCount)); unique.erase(sub);
    //         }
    //     }

    //     return maxCount;
    // }
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxUniqueSplit(s) << endl;
    }
    return 0;
}
