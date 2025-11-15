#include <bits/stdc++.h>
using namespace std;

Link : https://leetcode.com/problems/remove-linked-list-elements/

// new = building a house with special foundation.
// delete = calls the “demolish crew” that knows how to tear it down safely.
// malloc = building a tent.
// free = just rolls up the tent.

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