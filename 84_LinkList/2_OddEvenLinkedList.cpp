#include<bits/stdc++.h>
using namespace std;

// QUE : Odd Even Linked List

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

node* OddEvenLL(node* head)
{
    if(head == nullptr || (head->next == nullptr || head->next->next == nullptr)) return head;

    vector<int> arr;

    node* temp = head;
    while(temp != nullptr)
    {
        arr.push_back(temp->data);
        if(temp->next == nullptr) break;
        temp = temp->next->next;
    }

    temp = head->next;
    while(temp != nullptr)
    {
        arr.push_back(temp->data);
        if(temp->next == nullptr) break;
        temp = temp->next->next;
    }

    temp = head;
    int i = 0;
    while(temp != nullptr)
    {
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }
    
    return head;

    // TC : N
    // SC : N
}

node* OddEvenLL2(node* head)
{
    if (head == nullptr || head->next == nullptr) return head;

    // Initialize pointers for odd and even nodes
    node* odd = head;
    node* even = head->next;
    node* evenHead = even; // Keep track of the start of even nodes

    while (even != nullptr && even->next != nullptr) 
    {
        // Connect odd nodes
        odd->next = even->next;
        odd = odd->next;

        // Connect even nodes
        even->next = odd->next;
        even = even->next;
    }

    // Attach even nodes after the last odd node
    odd->next = evenHead;

    return head;

    // TC : N
    // SC : 1
}

int main()
{
    node* head = createLL(3);

    head = OddEvenLL2(head);
    printLL(head);

}