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

node* Arr2DLL(vector<int> arr, int n)
{
    node* head = new node(arr[0]);
    node* prev = head;

    for(int i=1; i<n; i++)
    {
        node* temp = new node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

void printRevDLL(node* head)
{
    node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->back;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();

    node* head = Arr2DLL(arr, n);

    printDLL(head);

    printRevDLL(head);

}