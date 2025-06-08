#include<bits/stdc++.h>
using namespace std;

// QUE : Remove Nth Node from the end of the LinkedList

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

node* removeNode(node* head, int k)
{
    // Calculating size of linklist
    int n = 0;
    node* temp = head;
    while(temp != nullptr)
    {
        n++;
        temp = temp->next;
    }

    int i = n-k; // ith element from begning
    int cnt = 0;
    temp = head;
    node* prev = head;

    if(i == 0)
    {
        temp = temp->next;
        head->next = nullptr;
        free(head);
        return temp;
    }

    while(temp != nullptr)
    {
        if(i == n)
        {
            prev->next = nullptr;
            free(temp);
            return head;
        }

        if(cnt == i)
        {
            prev->next = prev->next->next;
            temp->next = nullptr;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    // TC : 2N
    // SC : 1
}

node* removeNode1(node* head, int k)
{
    node* fast = head;
    while(k > 0)
    {
        fast = fast->next;
        k--;
    }

    node* slow = head;

    if(fast == nullptr)
    {
        slow = slow->next;
        head->next = nullptr;
        free(head);
        return slow;
    }

    while(fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    node* dump = slow->next;
    slow->next = slow->next->next;
    dump->next = nullptr;
    free(dump);
    return head;

    // TC : N
    // SC : 1
}

int main()
{
    node* head = createLL(6);

    head = removeNode1(head, 3);
    printLL(head);
}