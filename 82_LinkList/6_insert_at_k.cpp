#include<bits/stdc++.h>
using namespace std;

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

void printLL(node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

node* convertArr2LL(vector<int> arr)
{
    node* head = new node(arr[0]);
    node* mover = head;

    for(int i=1; i<arr.size(); i++)
    {
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

node* insertK(node* head, int val, int k)
{
    node* temp = head;
    int cnt = 0;

    while(temp != NULL)
    {
        cnt++;
        if(cnt == k-1)
        {
            node* x = new node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    node* head;
    head = convertArr2LL(arr);
    printLL(head);
    cout << endl;
    head = insertK(head, 10, 3);
    printLL(head);
}