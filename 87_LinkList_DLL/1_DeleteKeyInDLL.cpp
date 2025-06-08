#include<bits/stdc++.h>
using namespace std;

// QUE : Delete all occurrences of a Key in DLL

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

node* DeleteAllKeyOccurrences(node* head, int key) {
    node* curr = head;
    while (curr != nullptr) {
        if (curr->data == key) {
            // Key found, handle different cases
            if (curr->back && curr->next) {
                // Node has both previous and next
                node* left = curr->back;
                node* right = curr->next;
                left->next = right;
                right->back = left;
                free(curr);
                curr = left;
            } else if (curr->back == nullptr && curr->next) {
                // Node is the head
                head = curr->next;
                head->back = nullptr;
                free(curr);
                curr = head;
                continue;
            } else if (curr->back && curr->next == nullptr) {
                // Node is the tail
                node* temp = curr;
                curr = curr->back;
                curr->next = nullptr;
                free(temp);
            }
        }
        curr = curr->next;
    }
    if(head == Key) return nullptr;
    return head;
}
