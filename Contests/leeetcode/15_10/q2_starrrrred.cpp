#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        string ans = "";
        int len = s.size();
        int sstr = -1, send = -1;

        for (int start = 0; start < len; start++)
        {
            int count = 0;
            for (int i = start; i < len; i++)
            {
                if (s[i] == '1')
                    count++;

                if (count == k)
                {
                    if (k == 1)
                    {
                        return ans = '1';
                    }
                    if ((i - start) == (send - sstr))
                    {
                        int temp = i - start;
                        for (int j = 0; j <= temp; j++)
                        {
                            if (s[start + j] < s[sstr + j])
                            {
                                sstr = start;
                                send = i;
                            }
                            else if (s[start + j] > s[sstr + j])
                            {
                                break;
                            }
                        }
                    }
                    if (send == -1 || (i - start) < (send - sstr))
                    {
                        sstr = start;
                        send = i;
                    }
                    break;
                }
            }
        }

        if (sstr == -1 || send == -1)
        {
            return ans;
        }

        ans = s.substr(sstr, send - sstr + 1);
        return ans;
    }
};