#include <bits/stdc++.h>
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

node* delete_kth(node* head, int k)
{
    if(k == 1)
    {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    node* temp = head;
    int cnt = 0;
    node* prev = NULL;
    while(temp != NULL)
    {
        cnt++;
        if(cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {5,4,3,2,1};
    node* head = convertArr2LL(arr);
    printLL(head);
    cout << endl;
    head = delete_kth(head, 3);
    printLL(head);
}