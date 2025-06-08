#include<bits/stdc++.h>
using namespace std;

// QUE : Merge two sorted Linked Lists
// Link: https://bit.ly/3vjuaGQ

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


node* Brute(node* head1, node* head2)
{
    vector<int> arr;

    node* temp = head1;
    while(temp != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    temp = head2;
    while(temp != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    
    sort(arr.begin(), arr.end());

    temp = head1;
    int i = 0;
    node* prev;
    while(temp != nullptr)
    {
        prev = temp;
        temp->data = arr[i++];
        temp = temp->next;
    }

    prev->next = head2;

    temp = head2;
    while(temp != nullptr)
    {
        temp->data = arr[i++];
        temp = temp->next;
    } 

    return head1;

    // TC : N + M + (N+M)log(N+M) + N + M
    // SC : N + M
}

node* Optimal(node* head1, node* head2)
{
    node* dmy = new node(-1);

    node* temp = dmy;
    node* t1 = head1;
    node* t2 = head2;

    while(t1 && t2)
    {
        if(t1->data <= t2->data)
        {
            temp->next = t1;
            t1 = t1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = t2;
            t2 = t2->next;
            temp = temp->next;
        } 
    }

    if(t1) temp->next = t1;
    if(t2) temp->next = t2;

    node* head = dmy->next;
    dmy->next = nullptr;
    free(dmy);

    return head;

    // TC : N + M
    // SC : 1
}

int main()
{
    node* head1 = createLL(4);
    node* head2 = createLL(6);

    // node* head = Brute(head1, head2);
    // printLL(head);

    node* head = Optimal(head1, head2);
    printLL(head);


}

