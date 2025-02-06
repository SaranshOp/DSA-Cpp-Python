#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    ll a[N];

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    ll cnt = 0;
    sort(a, a + N);
    ll val = a[N - 1];

    for (int i = N - 2; i >= 0; i--)
    {
        if (a[i] % val == 0)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }

    cnt += 1;

    if (cnt == N)
    {
        cout << -1 << "\n";
        return;
    }

    cout << N - cnt << " " << cnt << "\n";

    for (int i = 0; i < N - cnt; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\n";

    for (int i = N - cnt; i < N; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}