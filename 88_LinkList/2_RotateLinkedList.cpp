#include<bits/stdc++.h>
using namespace std;

// QUE : Rotate a LinkedList
// Link: https://tinyurl.com/ye23ua58

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

node* rotateLL(node* head, int k)
{
    if(head == nullptr || k == 0) return head;

    int n = 1;
    node* tail = head;
    while(tail->next != nullptr)
    {
        tail = tail->next;
        n++;
    }

    k = k%n;
    if(k == 0) return head;

    int x = n-k;
    node* newTail = head;
    for(int i=1; i<x; i++) newTail = newTail->next;

    node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}