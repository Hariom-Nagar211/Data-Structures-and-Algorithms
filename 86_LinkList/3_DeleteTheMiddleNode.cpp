#include<bits/stdc++.h>
using namespace std;

// QUE : Delete the middle node of the LinkedList
// Link:   https://tinyurl.com/y2r52yz8

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

node* DeleteMiddleNode(node* head)
{
    node* dummy = new node(-1);
    if(head == nullptr || head->next == nullptr) return dummy;

    node* slow = head;
    node* fast = head;
    node* prev = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = prev->next->next;
    slow->next = nullptr;
    free(slow);
    return head;
}