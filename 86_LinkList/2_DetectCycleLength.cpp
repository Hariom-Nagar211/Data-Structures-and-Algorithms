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

// my way but ia modifyin the linklist, not a efficient way
int DetectCycleLength(node* head)
{
    while(temp != nullptr)
    {
        // Mark the current node as visited by using a sentinel value (-1 in this case)
        if (temp->data == -1) {
            break;  // A cycle is detected when we encounter a node already marked
        }

        // Mark the node as visited
        temp->data = -1;
        cnt++;
        temp = temp->next;
    }

    // If no cycle is found, return 0
    if (temp == nullptr)
        return 0;

    // Cycle detected, now we calculate the length of the cycle
    node* cycle_node = temp;
    int cycle_length = 1;
    temp = temp->next;

    while(temp != cycle_node)
    {
        cycle_length++;
        temp = temp->next;
    }

    // TC : 2N
    // SC : 1
}

// brute
int DetectCycleLength2(node* head)
{
    map<node*, pair<int,int>> mpp;
    node* temp = head;
    int cnt = 0;
    while(temp != nullptr)
    {
        if(mpp.find(temp) != mpp.end()) 
        {
            int lastPosition = mpp[temp].second;
            return cnt - lastPosition;
        }
        mpp[temp].first = 1;
        mpp[temp].second = cnt;
        cnt++;
        temp = temp->next;
    }
    return 0;

    // TC : N
    // SC : N
}

// best way (slow and fast)
int DetectCycleLength3(node* head)
{
    node* slow = head;
    node* fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            int cnt = 1;
            slow = slow->next;
            while(slow != fast)
            {
                slow = slow->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
}
