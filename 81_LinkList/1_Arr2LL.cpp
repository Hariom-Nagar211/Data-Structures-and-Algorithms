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

node* convertArr2LL(vector<int> &arr)
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

int lenOfLL(node* head)
{
    int cnt = 0;
    node* temp = head;
    while(temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool searchInLL(node* head, int val)
{
    node* temp = head;
    while(temp != nullptr)
    {
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    vector<int> arr = {11,2,3,4,5};
    node* head = convertArr2LL(arr);

    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl << lenOfLL(head) << endl;

    int val = 13;
    cout << searchInLL(head, val) << endl;
    
    
}