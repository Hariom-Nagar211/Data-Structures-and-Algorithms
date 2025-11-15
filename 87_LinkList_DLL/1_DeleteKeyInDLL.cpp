#include<bits/stdc++.h>
using namespace std;

// QUE : Delete all occurrences of a Key in DLL
// Link : https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1


// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        
        // deleting all occur at begning
        Node* curr = *head_ref;
        while(curr && curr->data == x)
        {
            Node* temp = curr;
            curr = curr->next;
            if(curr) curr->prev = nullptr;
            delete(temp);
        }
        
        // updating head
        *head_ref = curr;
        
        // deleting the rest nodes
        while(curr)
        {
            if(curr->data == x)
            {
                Node* temp = curr;
                
                Node* prev_node = curr->prev;
                Node* next_node = curr->next;
                if(prev_node) prev_node->next = next_node;
                if(next_node) next_node->prev = prev_node;
                
                curr = curr->next;
                delete(temp);
            }
            else curr = curr->next;
        }
        
    }
};