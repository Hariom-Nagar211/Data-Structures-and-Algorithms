#include<bits/stdc++.h>
using namespace std;

// QUE : Remove duplicates from sorted DLL
// Link: https://tinyurl.com/5n8ndcuu

struct node
{
    node* back;
    int data;
    node* next;

    node(node* back1, int data1, node* next1)
    {
        back = back1;
        data = data1;
        next = next1;
    }

    node(int data1)
    {
        back = nullptr;
        data = data1;
        next = nullptr;
    }
};

node* removeDuplicates(node* head)
{
    if(head == nullptr) return nullptr;

    node* prev = head;
    node* curr = head->next;
    
    while(curr != nullptr)
    {
        int key = prev->data;

        if(curr->data == key)
        {
            if(curr->next)
            {
                node* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                curr->back = prev;
                free(temp);
            }
            else
            {
                prev->next = nullptr;
                free(curr);
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;

}