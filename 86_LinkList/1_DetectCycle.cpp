#include<bits/stdc++.h>
using namespace std;

// QUE : Detect a loop or cycle in LinkedList

struct node
{
    int data;
    node* next;

    node(int data1, node* next1)
    {
        data = data1;
        next = next1;
    }

    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

node* createLL(int n)
{
    int val;
    cout << "Enter Linklist : ";
    cin >> val;
    node* head = new node(val);
    node* mover = head;
    
    for(int i=1; i<n; i++)
    {
        int val;
        cin >> val;
        node* temp = new node(val);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(node* head)
{
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void joinLL(node* head1, node* head2, int Y)
{
    node* jn = head1;
    for(int i=1; i<Y; i++)
    {
        jn = jn->next;
    }

    node* lastNode = head2;
    while(lastNode->next != nullptr) lastNode = lastNode->next;

    lastNode->next = jn;
}

// my way(but i am temporing the main data)
bool DetectLoop(node* head)
{
    node* temp = head;
    while(temp != nullptr)
    {
        if(temp->data == -1) return true;
        temp->data = -1;
        temp = temp->next;
    }
    return false;

    // TC : N
    // SC : 1
}

// brute
bool DetectLoop2(node* head)
{
    map<node*, int> mpp;
    node* temp = head;
    while(temp != nullptr)
    {
        if(mpp.find(temp) == 1) return true;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

// best solution : slow and fast pointers

int main()
{
    node* head = createLL(9);
    node* temp1 = head;
    while(temp1->data != 4) temp1 = temp1->next;
    node* temp2 = head;
    while(temp2->next != nullptr) temp2 = temp2->next;
    temp2->next = temp1;

    cout << DetectLoop(head);


}