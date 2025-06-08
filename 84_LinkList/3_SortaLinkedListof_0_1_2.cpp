#include<bits/stdc++.h>
using namespace std;

// QUE : Sort a LinkList of 0's 1's and 2's

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

node* SortLL(node* head)
{
    int cnt_0s = 0;
    int cnt_1s = 0;
    int cnt_2s = 0;
    node* temp = head;

    while(temp != nullptr)
    {
        if(temp->data == 0) cnt_0s++;
        else if(temp->data == 1) cnt_1s++;
        else cnt_2s++;
        temp = temp->next;
    }

    temp = head;
    for(int i=0; i<cnt_0s; i++)
    {
        temp->data = 0;
        temp = temp->next;
    }
    for(int i=0; i<cnt_1s; i++)
    {
        temp->data = 1;
        temp = temp->next;
    }
    for(int i=0; i<cnt_2s; i++)
    {
        temp->data = 2;
        temp = temp->next;
    }

    // temp = head;
    // while(temp != nullptr)
    // {
    //     if(cnt_0s > 0)
    //     {
    //         temp->data = 0;
    //         temp = temp->next;
    //         cnt_0s--;
    //     }
    //     else if(cnt_1s > 0)
    //     {
    //         temp->data = 1;
    //         temp = temp->next;
    //         cnt_1s--;
    //     }
    //     else
    //     {
    //         temp->data = 2;
    //         temp = temp->next;
    //         cnt_2s--;
    //     } 
    // }

    return head;

    // TC : 2N
    // SC : 1
}

node* SortLL2(node* head)
{
    node* temp = head;
    node* zeroHead = new node(-1);
    node* oneHead = new node(-1);
    node* twoHead = new node(-1);
    node* zero = zeroHead;
    node* one = oneHead;
    node* two = twoHead;

    while(temp != nullptr)
    {
        if(temp->data == 0)
        {
            zero->next = temp;
            temp = temp->next;
            zero = zero->next;
        }
        else if(temp->data == 1)
        {
            one->next = temp;
            temp = temp->next;
            one = one->next;
        }
        else
        {
            two->next = temp;
            temp = temp->next;
            two = two->next;
        }
    }
    temp = zeroHead;
    zeroHead = zeroHead->next;
    free(temp);

    temp = oneHead;
    oneHead = oneHead->next;
    free(temp);

    temp = twoHead;
    twoHead = twoHead->next;
    free(temp);

    zero->next = oneHead;
    one->next = twoHead;

    return zeroHead;

    // TC : N
    // SC : 1
}

int main()
{
    node* head = createLL(6);

    head = SortLL2(head);
    printLL(head);
}