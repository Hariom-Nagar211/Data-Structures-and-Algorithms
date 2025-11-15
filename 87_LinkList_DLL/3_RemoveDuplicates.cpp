#include<bits/stdc++.h>
using namespace std;

// QUE : Remove duplicates from sorted DLL
// Link: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        
        if (!head) return nullptr;

        Node* curr = head;

        while (curr && curr->next) {
            if (curr->data == curr->next->data) {
                // Duplicate node is curr->next
                Node* duplicate = curr->next;
                Node* next_node = duplicate->next;

                curr->next = next_node;
                if (next_node) next_node->prev = curr;

                delete duplicate; // free memory
            } else {
                curr = curr->next; // move forward if no duplicate
            }
        }

        return head;
        
    }
};