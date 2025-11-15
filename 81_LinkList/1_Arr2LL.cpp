#include<bits/stdc++.h>
using namespace std;

// Definition of a node in the linked list
struct node
{
    int data;      // Value stored in the node
    node* next;    // Pointer to the next node

    // Constructor to initialize both data and next pointer
    node(int data1, node* next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor to initialize only data, next is set to nullptr
    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to convert an array to a linked list
node* convertArr2LL(vector<int> &arr)
{
    // Create the head node with the first element of the array
    node* head = new node(arr[0]);
    node* mover = head; // Pointer to traverse and build the list

    // Loop through the rest of the array and add nodes
    for(int i=1; i<arr.size(); i++)
    {
        node* temp = new node(arr[i]); // Create new node
        mover->next = temp;            // Link previous node to new node
        mover = temp;                  // Move to the new node
    }
    return head; // Return the head of the linked list
}

// Function to calculate the length of the linked list
int lenOfLL(node* head)
{
    int cnt = 0;           // Counter for nodes
    node* temp = head;     // Pointer to traverse the list
    while(temp != nullptr) // Traverse until end of list
    {
        temp = temp->next; // Move to next node
        cnt++;             // Increment counter
    }
    return cnt;            // Return total count
}

// Function to search for a value in the linked list
bool searchInLL(node* head, int val)
{
    node* temp = head;     // Pointer to traverse the list
    while(temp != nullptr) // Traverse until end of list
    {
        if(temp->data == val) return true; // If value found, return true
        temp = temp->next;              // Move to next node
    }
    return false; // Value not found, return false
}

int main()
{
    // Create an array of integers
    vector<int> arr = {11,2,3,4,5};
    // Convert array to linked list
    node* head = convertArr2LL(arr);

    // Print the linked list
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " "; // Print current node's data
        temp = temp->next;         // Move to next node
    }

    cout << endl << lenOfLL(head) << endl; // Print length of linked list

    int val = 13; // Value to search in the linked list
    cout << searchInLL(head, val) << endl; // Print result of search (1 if found, 0 if not)
}