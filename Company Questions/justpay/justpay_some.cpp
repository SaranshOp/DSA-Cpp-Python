#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure to represent each employee
struct Employee
{
    int supervisor;           // Immediate supervisor
    bool compliant;           // Compliance status (true for compliant, false for non-compliant)
    vector<int> subordinates; // List of subordinates
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<Employee> employees(n + 1);
    vector<int> inDegree(n + 1, 0); // To keep track of the number of subordinates of each employee

    // Input for each employee
    for (int i = 1; i <= n; i++)
    {
        int p, c;
        cin >> p >> c;
        employees[i].supervisor = p;
        employees[i].compliant = (c == 0); // 0 for compliant, 1 for non-compliant
        if (p != -1)
        {
            employees[p].subordinates.push_back(i);
            inDegree[p]++;
        }
    }

    queue<int> removableQueue;

    // Initial pass to find non-compliant employees with no compliant subordinates
    for (int i = 1; i <= n; i++)
    {
        if (!employees[i].compliant && inDegree[i] == 0)
        {
            removableQueue.push(i);
        }
    }

    vector<int> removalOrder;

    // Process removal of employees
    while (!removableQueue.empty())
    {
        int current = removableQueue.front();
        removableQueue.pop();
        removalOrder.push_back(current);

        int supervisor = employees[current].supervisor;
        if (supervisor != -1)
        {
            // Remove this subordinate from its supervisor
            inDegree[supervisor]--;

            // Check if supervisor becomes removable
            bool supervisorRemovable = true;
            for (int sub : employees[supervisor].subordinates)
            {
                if (employees[sub].compliant)
                {
                    supervisorRemovable = false;
                    break;
                }
            }

            if (supervisorRemovable && !employees[supervisor].compliant && inDegree[supervisor] == 0)
            {
                removableQueue.push(supervisor);
            }
        }
    }

    if (removalOrder.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (int id : removalOrder)
        {
            cout << id << " ";
        }
        cout << endl;
    }

    return 0;
}