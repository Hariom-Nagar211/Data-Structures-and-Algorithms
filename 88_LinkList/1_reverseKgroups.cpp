#include<bits/stdc++.h>
using namespace std;

// QUE : Reverse Nodes in K Group Size of LinkedList
// Link: https://tinyurl.com/4dbz8fnn

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

node* reverseLL(node* head)
{
    node* left = nullptr;
    node* curr = head;
    while(curr != nullptr)
    {
        node* temp = curr->next;
        curr->next = left;
        left = curr;
        curr = temp;
    }
    return left;
}

node* findkthNode(node* temp, int k)
{
    k -= 1;
    while(temp != nullptr && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

node* kReverse(node* head, int k) 
{
    node* temp = head;
    node* nextNode = nullptr;
    node* prevNode = temp;
    while(temp != nullptr)
    {
        node* kthNode = findkthNode(temp, k);
        if(kthNode == nullptr)
        {
            if(prevNode) prevNode->next = temp;
            break;
        }

        nextNode = kthNode->next;
        kthNode->next = nullptr;

        reverseLL(temp);

        if(temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}