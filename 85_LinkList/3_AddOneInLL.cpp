#include<bits/stdc++.h>
using namespace std;

// QUE : Add 1 to a number represented by LinkedList

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

node* addOne(node* head)
{
    if(head == nullptr) return nullptr;

    node* temp = head;
    int len = 0;
    int num = 0;
    int last_num = head->data;
    node* last_ptr = nullptr;
    while(temp != nullptr)
    {
        num = num*10 + (temp->data);
        len = len + 1;
        if(temp->next == nullptr) last_ptr = temp;
        temp = temp->next;
    }

    if(last_ptr->data < 9)
    {
        last_ptr->data = (last_ptr->data) + 1;
        return head;
    }
    else
    {
        num = (num + 1);
        if(num/static_cast<int>(pow(10,len)) == 1) // 9 9 9 9 ...
        {
            head->data = 1;
            temp = head->next;
            while(temp->next != nullptr) 
            {
                temp->data = 0;
                temp = temp->next;
            }
            node* lastNode = new node(0);
            temp->data = 0;
            temp->next = lastNode;

            return head;
        }
        else // not 9 9 9 ...
        {
            len = len - 1;
            temp = head;
            while(temp != nullptr)
            {
                int digit = static_cast<int>(num/(pow(10,len)));
                num = static_cast<int>(num % static_cast<int>(pow(10, len))); // some error in this loop
                temp->data = digit;
                len--;
                temp = temp->next; 
            }
            return head;

        }
    }
}

int main()
{
    node* head = createLL(3);
    
    head = addOne(head);
    printLL(head);


}