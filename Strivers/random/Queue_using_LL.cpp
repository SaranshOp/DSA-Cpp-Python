#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class QueueNode
{
public:
    int val;
    QueueNode* next;
    QueueNode(int data){
        val = data;
        next = NULL;
    }
};
QueueNode *Front = nullptr, *Rare = nullptr;

class QueueLL
{
    public:
    void Enqueue(int value);
    void dequeue();
    int top();
    void size();
    bool isempty();
};
bool QueueLL ::  isempty()
{
    return Front == nullptr;
}  
void QueueLL :: Enqueue(int val){
    QueueNode* temp =  new QueueNode(val);
    if(temp == nullptr){
        cout << "Queue is full" << endl;
        return;
    }
    else{
        if(Front == nullptr){
            Front = temp;
            Rare = temp;
        }
        else{
            Rare->next = temp;
            Rare = temp;  
    }
}
}

void QueueLL :: dequeue(){
    if( isempty()){
        cout << "Queue is empty" << endl;
        return;
    }
    else{QueueNode* temp = Front;
        Front = Front->next;
        delete temp;
    }
}

void QueueLL :: size(){
    int count = 0;
    QueueNode* temp = Front;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    cout << "Size of the Queue is: " << count << endl;
}

int QueueLL :: top(){
    if(isempty()){
        cout << "Queue is empty" << endl;
        return -1;
    }
    else{
        return Front->val;
    }
}   
int main()
{
    QueueLL Q;
    
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.size();
    cout << Q.top() << endl;
    Q.dequeue();
    cout << Q.top() << endl;
    Q.size();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.size();
    cout << Q.top() << endl;
    

    return 0;
}