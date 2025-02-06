#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t = "ABC";
    string s = "ADOBECODEBANC";

    int arrnum[256] = {0};

    for (int i = 0; i < t.size(); i++)
    {
        arrnum[t[i]]++;
    }

    int l = 0, r = 0, minsize = INT_MAX;
    int count = 0;
    int n = t.size(), m = s.size();
    int idx = -1;
    while (r < m)
    {

        if (arrnum[s[r]] > 0)
        {
            arrnum[s[r]]--;
            count++;
            while (count == n)
            {
                if (r - l + 1 <= minsize)
                {
                    minsize = r - l + 1;
                    idx = l;
                }
                arrnum[s[l]]++;
                if (arrnum[s[l]] > 0)
                    count--;
                l++;
            }
        }
        else
        {
            arrnum[s[r]]--;
        }
        r = r + 1;
    }
    string a = (idx == -1) ? "NA" : s.substr(idx, minsize);
    cout << a;
    return 0;
}