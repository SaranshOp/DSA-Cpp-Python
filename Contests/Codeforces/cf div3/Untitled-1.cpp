#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    string name = "vika";

    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        string carpetlines;
        cin >> carpetlines;
        v.push_back(carpetlines);
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[j][i] == name[count])
            {
                count++;
                break;
            }
        }
        if (count == 4)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << count;
    if (count == 4)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}