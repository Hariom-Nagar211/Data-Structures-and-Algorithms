#include<bits/stdc++.h>
using namespace std;

// QUE : Given two numbers in linklist in reverse order, sum up them and return the result in
//       linklist in reverse order.

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
}

node* add2num(node* head1, node* head2)
{
    node* temp1 = head1;
    node* temp2 = head2;
    node* box1 = new node(0);
    node* head = box1;
    int prev_carry = 0;
    node* prev;
    while(temp1 != nullptr)
    {
        int sum = (temp1->data) + (temp2->data);
        int num = sum%10;
        int new_carry = sum/10;

        prev = box1;
        node* box2 = new node(0);
        box1->data = num + prev_carry;
        box1->next = box2;
        box1 = box1->next;

        prev_carry = new_carry;

        temp1 = temp1->next;
        temp2 = temp2->next;

    }

    if(prev_carry > 0) box1->data = prev_carry;
    else prev->next = nullptr, free(box1);

    return head;
}

int main()
{
    node* head1 = createLL(3);
    node* head2 = createLL(3);

    node* head = add2num(head1, head2);
    printLL(head);

}
