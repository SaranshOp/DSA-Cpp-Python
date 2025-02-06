#include <bits/stdc++.h>
using namespace std;

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

        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        bool k = false;
        for (int i = 0; i <= 6; i++)
        {
            if (x.find(s) != -1)
            {
                k = true;
                cout << i << endl;
                break;
            }
            x += x;
        }
        if (!k)
            cout << "-1" << endl;
    }
    return 0;
}