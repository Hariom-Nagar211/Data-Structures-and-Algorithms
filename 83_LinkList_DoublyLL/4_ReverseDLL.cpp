#include<bits/stdc++.h>
using namespace std;

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

node* createDLL(int n)
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
        temp->back = mover;
        mover = temp;
    }
    return head;
}

void printDLL(node* head)
{
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* ReverseDLL(node* head)
{
    node* temp = head;
    stack<int> st;
    while(temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != nullptr)
    {
        temp->data = st.top();
        temp = temp->next;
        st.pop();
    }
    return head;

    // TC : 2N
    // SC : N
}

node* ReverseDLL2(node* head)
{
    node* curr = head;
    node* last = nullptr;
    while(curr != nullptr)
    {
        last = curr->back;
        curr->back = curr->next;
        curr->next = last;
        curr = curr->back;
    }
    return last->back;

    // TC : N
    // SC : 1
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    node* head = createDLL(n);
    head = ReverseDLL2(head);
    printDLL(head);
}