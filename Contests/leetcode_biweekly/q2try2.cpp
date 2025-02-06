#include <iostream>
#include <vector>

using namespace std;

vector<string> longestUnequalAdjacentGroupsSubsequence(int n, vector<string> &words, vector<int> &groups)
{
    int maxlen = 0;
    vector<int> indices;
    vector<string> ans;
    int last = groups[0];
    indices.push_back(0);
    for (int i = 1; i < groups.size(); i++)
    {
        if (groups[i] == last)
        {
            continue;
        }
        last = groups[i];
        indices.push_back(i);
    }
    for (int i = 0; i < indices.size(); i++)
    {
        ans.push_back(words[indices[i]]);
        /// cout<<indices[i]<<" "; ans.push_back(words[indices[i]]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<string> words(n);
    vector<int> groups(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> groups[i];
        // cout << "i : grp: " << i << groups[i] << endl;
    }
    vector<string> longest_subsequence = longestUnequalAdjacentGroupsSubsequence(n, words, groups);
    for (string word : longest_subsequence)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}