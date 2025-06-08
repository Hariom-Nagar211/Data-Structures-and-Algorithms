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

node* insertK(node* head, int k, int val)
{
    if(head == nullptr && k == 1)
    {
        head->data = val;
        head->back = nullptr;
        head->next = nullptr;
        return head;
    }
    if(head == nullptr && k > 1) return nullptr;

    if(k == 1)
    {
        node* temp = new node(val);
        head->back = temp;
        temp->next = head;
        head = temp;
        return head;
    }

    node* prev = head;
    node* temp = head->next;
    int cnt = 2;
    while(temp != nullptr)
    {
        if(cnt == k)
        {
            node* curr = new node(val);
            prev->next = curr;
            curr->back = prev;
            curr->next = temp;
            temp->back = curr;
            return head;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;

}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();

    node* head = Arr2DLL(arr, n);

    head = insertK(head, 1, 10);
    printDLL(head);

}