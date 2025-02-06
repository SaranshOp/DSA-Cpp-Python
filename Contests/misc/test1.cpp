#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char c)
    {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') ||
               (c == 'u');
    }
    int countOfSubstrings(string word, int k)
    {
        int ans = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < word.size(); i++)
        {
            //cout << "i: " << i << endl;
            int cCount = 0, vCount = 0;
            mp.clear(); // was missing this line
            for (int j = i; j < word.size(); j++)
            {
                //cout << word[j] << " ";
                if (isVowel(word[j]))
                {
                    mp[word[j]]++;
                    if (mp[word[j]] == 1)
                        vCount++;
                }
                else
                {
                    cCount++;
                }
                //cout << vCount << " " << cCount << endl;
                if (vCount == 5 && cCount == k)
                {
                    ans++;
                    //cout << ans << endl;
                }
                if (cCount > k)
                    break;
            }
        }
        return ans;
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

    Solution s;
    // cout << s.countOfSubstrings("aeioqq", 1) << endl;         // Expected output: 0
    // cout << s.countOfSubstrings("aeiou", 0) << endl;          // Expected output: 1
    cout << s.countOfSubstrings("ieaouqqieaouqq", 1) << endl; // Expected output: 3
    // cout << s.countOfSubstrings("iqeaouqi", 2) << endl;       // Expected output: 3
    // cout << s.countOfSubstrings("eauiuo", 0) << endl;         // Expected output: 1
    // cout << s.countOfSubstrings("onauoeij", 1) << endl;       // Expected output: 3

    return 0;
}
