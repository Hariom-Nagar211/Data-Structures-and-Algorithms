#include<bits/stdc++.h>
using namespace std;

// QUE : Reverse a LinkList
// Link : https://leetcode.com/problems/reverse-linked-list/

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

node* ReverseLL(node* head)
{
    node* back = head;
    node* mid = head->next;
    node* front = head->next->next;

    while(mid != nullptr)
    {
        mid->next = back;
        back = mid;
        mid = front;
        if(front) front = front->next;
    }
    return back;
}

node* ReverseLL2(node* &back, node* &mid, node* &front)
{
    if(mid == nullptr) return back;

    mid->next = back;
    back = mid;
    mid = front;
    if(front) front = front->next;
    
    return ReverseLL2(back, mid, front);

}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* next_node = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next_node;
        }
        return prev;
    }
};