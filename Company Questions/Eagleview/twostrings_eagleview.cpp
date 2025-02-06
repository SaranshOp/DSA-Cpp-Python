#include <iostream>
#include <string>
using namespace std;

int solution(string &S, string &T)
{
    int n1 = S.size(), n2 = T.size();
    if (n1 != n2)
        return -1;
    int Tcnt = 0;

    for (int i = 0; i < n1 - 1; i++)
    {
        int cnt = 0;
        int SE1 = S[i] - '0';
        int TE1 = T[i] - '0';
        int SE2 = S[i + 1] - '0';
        int TE2 = T[i + 1] - '0';

        cout << "S: " << S << " T: " << T << endl;
        cout << "type of SE1: " << typeid(SE1).name() << endl;
        cout << "SE1 TE1 SE2 TE2: " << SE1 << ":" << TE1 << ":" << SE2 << ":" << TE2 << endl;
        
        if (SE1 == TE1)
            continue;

        if (SE1 < TE1)
        {
            cnt = TE1 - SE1;
            SE1 = (SE1 + cnt) % 10;
            SE2 = (SE2 + cnt) % 10;
        }
        else
        {
            cnt = 10 + TE1 - SE1;
            SE1 = (SE1 + cnt) % 10;
            SE2 = (SE2 + cnt) % 10;
        }
        S[i] = SE1 + '0';     
        S[i + 1] = SE2 + '0';  
        
        cout << "cnt : " << cnt << endl;
        Tcnt += cnt;
        cout << "Tcnt : " << Tcnt << endl;
    }

    if (S[n1 - 1] != T[n2 - 1])
        return -1;
    return Tcnt;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int k;
    cin >> k;
    while (k--)
    {
        string S, T;
        cin >> S >> T;
        cout << "S: " << S << " T: " << T << endl;
        int result = solution(S, T);
        cout << "Minimum moves: " << result << endl;
    }
}
