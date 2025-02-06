#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class StackNode
{
public:
    int val;
    StackNode *next;
    StackNode(int data)
    {
        val = data;
        next = NULL;
    }
};

class StackLL
{
public:
    int size = 0;
    void push();
    void pop();
    int top();
    void size();
    bool isempty();
};

int main()
{

    return 0;
}