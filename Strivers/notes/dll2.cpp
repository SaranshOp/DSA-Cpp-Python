#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    long long x = 0, y = 0;
    int i = 0;

    while (temp1 != NULL)
    {
        int t1 = temp1->val;
        x += pow(10, i) * t1;
        temp1 = temp1->next;
        i += 1;
    }

    i = 0;
    while (temp2 != NULL)
    {
        int t2 = temp2->val;
        y += pow(10, i) * t2;
        temp2 = temp2->next;
        i += 1;
    }

    int z = x + y;
    ListNode *head = new ListNode(z % 10);
    ListNode *temp = head;
    z /= 10;

    while (z > 0)
    {
        ListNode *n1 = new ListNode(z % 10);
        temp->next = n1;
        temp = n1;
        z /= 10;
    }

    return head;
}

int main()
{
    // Test Case 1: Adding two empty lists
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    ListNode *result = addTwoNumbers(l1, l2);
    // Expected: nullptr

    // Test Case 2: Adding two non-empty lists with single digits
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    result = addTwoNumbers(l1, l2);
    // Expected: 7 -> 0 -> 8

    return 0;
}