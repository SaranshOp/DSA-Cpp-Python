#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_divisor(int a, int b)
{
    return a % b == 0;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        vector<int> b, c;

        c.push_back(a[0]);

        for (int i = 1; i < n; ++i)
        {
            bool found = false;
            for (int j : c)
            {
                if (is_divisor(a[i], j))
                {
                    c.push_back(a[i]);
                    found = true;
                    break;
                }
            }
            if (found)
                continue;
            b.push_back(a[i]);
        }
        if (b.empty() || c.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            // Output the solution
            cout << b.size() << " " << c.size() << endl;
            for (int num : b)
            {
                cout << num << " ";
            }
            cout << endl;
            for (int num : c)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }
}
