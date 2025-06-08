#include<bits/stdc++.h>
using namespace std;

// QUE : Flattening a LinkedList
// Link: https://tinyurl.com/2p9ns48e 

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

node* createVerticalLL(vector<int> arr, int n)
{
    node* head = new node(arr[0]);
    node* temp = head;
    for(int i=1; i<n; i++)
    {
        node* newNode = new node(arr[i]);
        temp->child = newNode;
        temp = temp->child;
    }

    return head;
}

node* Brute(node* head)
{
    vector<int> arr;
    node* temp = head;
    while(temp != nullptr)
    {
        node* t2 = temp;
        while(t2 != nullptr)
        {
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());

    return createVerticalLL(arr);

    // let p = n*m
    // TC : p + plogp + p
    // SC : p + p
}

// optimal approach

class Node {
public:
    int data;
    Node *next;
    Node *child;

    // Constructors to initialize the
    // data, next, and child pointers
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

// Merges two linked lists in a particular
// order based on the data value
Node* merge(Node* list1, Node* list2){
    // Create a dummy node as a
    // placeholder for the result
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    // Merge the lists based on data values
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    // Connect the remaining
    // elements if any
    if(list1){
        res->child = list1;
    } else {
        res->child = list2;
    }

    // Break the last node's
    // link to prevent cycles
    if(dummyNode->child){
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}

// Flattens a linked list with child pointers
Node* flattenLinkedList(Node* head){
    // If head is null or there 
    // is no next node, return head
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Recursively flatten the
    // rest of the linked list
    Node* mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}

// Print the linked list by
// traversing through child pointers
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

// Print the linked list
// in a grid-like structure
void printOriginalLinkedList(Node* head, int depth) {
    while (head != nullptr) {
        cout << head->data;

        // If child exists, recursively
        // print it with indentation
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars
        // for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {
    // Create a linked list with child pointers
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(10);
    head->next->child = new Node(4);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // Print the original
    // linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Flatten the linked list
    // and print the flattened list
    Node* flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}

                                
                            

