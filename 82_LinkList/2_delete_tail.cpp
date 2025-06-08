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
        data =data1;
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

node* deleteTail(node* head)
{
    if(head == NULL || head->next == NULL) return NULL;

    node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

int main()
{
    vector<int> arr = {5,4,3,2,1};
    node* head = convertArr2LL(arr);
    printLL(head);
    deleteTail(head);
    cout << endl;
    printLL(head);

}


