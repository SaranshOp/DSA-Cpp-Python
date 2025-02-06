#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool is_divisor(int a, int b) {
    return b % a == 0;
}

pair<vector<int>, vector<int>> find_partition(int n, vector<int>& a) {
    vector<int> b, c;
    b.push_back(a[0]);

    for (int i = 1; i < n; ++i) {
        bool can_add_to_b = true;
        for (int bi : b) {
            if (is_divisor(a[i], bi)) {
                can_add_to_b = false;
                break;
            }
        }

        if (can_add_to_b) {
            b.push_back(a[i]);
        } else {
            c.push_back(a[i]);
        }
    }

    if (b.empty() || c.empty()) {
        return make_pair(vector<int>(), vector<int>());
    }

    return make_pair(b, c);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        auto result = find_partition(n, a);
        if (result.first.empty() || result.second.empty()) {
            cout << -1 << endl;
        } else {
            cout << result.first.size() << " ";
            for (int num : result.first) {
                cout << num << " ";
            }
            cout << endl;

            cout << result.second.size() << " ";
            for (int num : result.second) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
