#include<bits/stdc++.h>
using namespace std;

// QUE : Find the intersection point of Y LinkedList

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

void joinLL(node* head1, node* head2, int Y)
{
    node* jn = head1;
    for(int i=1; i<Y; i++)
    {
        jn = jn->next;
    }

    node* lastNode = head2;
    while(lastNode->next != nullptr) lastNode = lastNode->next;

    lastNode->next = jn;
}

node* findIntersection(node* head1, node* head2)
{
    // Marking First LL
    vector<int> arr;
    node* temp = head1;
    while(temp != nullptr)
    {
        arr.push_back(temp->data);
        temp->data = -1;
        temp = temp->next;
    }

    // Finding Junction
    node* junction = nullptr;
    temp = head2;
    while(temp != nullptr)
    {
        if(temp->data == -1)
        {
            junction = temp;
            break;
        }
        temp = temp->next;
    }

    // Removing Markings
    temp = head1;
    int i = 0;
    while(temp != nullptr)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    return junction;

    // TC : n + m + n
    // SC : n
}

int main()
{
   node* head1 = createLL(5);
   node* head2 = createLL(4);
   joinLL(head1, head2, 3);

    node* jn = findIntersection(head1, head2);
    printLL(jn);

}