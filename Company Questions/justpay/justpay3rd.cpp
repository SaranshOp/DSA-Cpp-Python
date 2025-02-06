#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the coolest peak temperature for a given window size s
int find_coolest_peak(const vector<int> &temperatures, int n, int s)
{
    deque<int> deq;
    vector<int> max_in_windows;

    // Process the first s elements
    for (int i = 0; i < s; ++i)
    {
        while (!deq.empty() && temperatures[deq.back()] <= temperatures[i])
            deq.pop_back();
        deq.push_back(i);
    }

    // Process the rest of the elements
    for (int i = s; i < n; ++i)
    {
        // Append the maximum of the current window
        max_in_windows.push_back(temperatures[deq.front()]);

        // Remove the elements which are out of this window
        while (!deq.empty() && deq.front() <= i - s)
            deq.pop_front();

        // Remove elements that are smaller than the current element
        while (!deq.empty() && temperatures[deq.back()] <= temperatures[i])
            deq.pop_back();

        deq.push_back(i);
    }

    // Append the maximum for the last window
    max_in_windows.push_back(temperatures[deq.front()]);

    // Return the coolest (minimum) peak temperature
    return *min_element(max_in_windows.begin(), max_in_windows.end());
}

int main()
{
    int n, q;

    // Input n (number of days) and q (number of queries)
    cin >> n >> q;

    // Input temperature readings
    vector<int> temperatures(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> temperatures[i];
    }

    // Process each query
    for (int i = 0; i < q; ++i)
    {
        int s;
        cin >> s;

        // Find the coolest peak for the current window size s
        cout << find_coolest_peak(temperatures, n, s) << endl;
    }

    return 0;
}
