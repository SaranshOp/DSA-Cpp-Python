#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class Solution
{
public:
    int countOfSubstrings(string word, int k)
    {

        int n = word.size();
        unordered_map<char, int> mp;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (auto c : vowels)
        {
            mp[c] = 0;
        }
        int vowel_count = 0;
        int consonent_count = 0;
        int start = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (vowels.find(word[i]) != vowels.end())
            {
                if (mp[word[i]] == 0)
                    vowel_count++;
                mp[word[i]]++;
            }
            else
            {
                consonent_count++;
            }
            while (consonent_count > k)
            {
                if (vowels.find(word[start]) != vowels.end())
                {
                    mp[word[start]]--;
                    if (mp[word[start]] == 0)
                        vowel_count--;
                }
                else
                {
                    consonent_count--;
                }
                start++;
            }
            // cout << vowel_count << " " << consonent_count << endl;
            if (consonent_count == k && vowel_count == 5)
            {
                // cout << word.substr(start, i - start + 1) << endl;
                count++;
                int temp_start = start;
                unordered_map<char, int> temp_mp = mp;
                while (temp_start < i && vowels.find(word[temp_start]) != vowels.end())
                {
                    if (temp_mp[word[temp_start]] == 1)
                        break;
                    temp_mp[word[temp_start]]--;
                    count++;
                    temp_start++;
                }
            }
        }
        return count;
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
    // cout << s.countOfSubstrings("aeioqq", 1) << endl;         // 0
    // cout << s.countOfSubstrings("aeiou", 0) << endl;          // 1
    // cout << s.countOfSubstrings("ieaouqqieaouqq", 1) << endl; // 3
    // cout << s.countOfSubstrings("iqeaouqi", 2) << endl;       // 3
    // cout << s.countOfSubstrings("eauiuo", 0) << endl;         // 1
    // cout << s.countOfSubstrings("onauoeij", 1) << endl;       // 3
    // cout << s.countOfSubstrings("aaccoiudie", 3) << endl;     // 2
    //  cout << s.countOfSubstrings("aoeeaeiuoieiueiieuiiuoiaieeoeaauauuiaiu", 0) << endl; // 449
    return 0;
}
