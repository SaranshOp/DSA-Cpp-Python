#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node
{
    //     int data = temp;
    //     node* next = NULL;
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *temp1)
    {
        data = data1;
        next = temp1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convARRtoLL(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *n1 = new Node(arr[i]);
        temp->next = n1;
        temp = n1;
    }
    return head;
}

void printLL(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << " -> " << temp->data;
        temp = temp->next;
    }
    return;
}

main()
{
    int n = 5;
    int arry[n] = {21, 22, 23, 24, 45};

    Node *heady = convARRtoLL(arry, n);
    printLL(heady);

    return 0;
}