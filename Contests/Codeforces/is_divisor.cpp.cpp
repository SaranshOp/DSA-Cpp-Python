#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_divisor(int a, int b) {
    return a % b == 0 || b % a == 0;
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

        vector<int> b, c;
        bool found = false;

        // Try to place elements in b, ensuring no element in c is a divisor of an element in b
        for (int i = 0; i < n; ++i) {
            bool can_place_in_b = true;
            for (int j : b) {
                if (is_divisor(a[i], j)) {
                    can_place_in_b = false;
                    break;
                }
            }

            if (can_place_in_b) {
                b.push_back(a[i]);
            } else {
                c.push_back(a[i]);
            }
        }

        // Check if a solution is possible
        if (b.empty() || c.empty()) {
            cout << -1 << endl;
        } else {
            // Output the solution
            cout << b.size() << " " << c.size() << endl;
            for (int num : b) {
                cout << num << " ";
            }
            cout << endl;
            for (int num : c) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
