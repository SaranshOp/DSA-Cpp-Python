#include <iostream>
#include <vector>

using namespace std;

bool can_color_array(int n, vector<int>& arr) {
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
    }

    if ((odd_count % 2 ) == 0)
        return true;
    else
        return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        bool result = can_color_array(n, arr);
        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}

















/*
def can_color_array(n, arr):
    even_count = sum(1 for num in arr if num % 2 == 0)
    odd_count = n - even_count

    if even_count == 0 or odd_count == 0:
        return "NO"
    else:
        return "YES"

// Read the number of test cases
t = int(input())

// Process each test case
for _ in range(t):
    // Read the length of the array and the array elements
    n = int(input())
    arr = list(map(int, input().split()))

     // Check if the array can be colored as required and print the result
    result = can_color_array(n, arr)
    print(result)
*/