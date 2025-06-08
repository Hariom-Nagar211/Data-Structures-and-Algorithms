#include<bits/stdc++.h>
using namespace std;

// QUE : Detect a loop or cycle length in LinkedList
// Link:  https://tinyurl.com/5n78kcda

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

node* FirstNodeOfCycle(node* head)
{
    node* slow = head;
    node* fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;

}