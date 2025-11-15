#include<bits/stdc++.h>
using namespace std;

// QUE : CheckPalindrome
// Note : Important que whatch striver video complete
// Link : https://leetcode.com/problems/palindrome-linked-list/

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

// by using stack : TC - 2N and SC : N

node* findMid(node* head, int &is_odd)
{
    if(head == nullptr) return nullptr;

    node* slow = head;
    node* fast = head;

    while(fast != nullptr)
    {
        if(fast->next == nullptr)
        {
            is_odd = 1;
            return slow;
        }
        if(fast->next->next == nullptr)
        {
            is_odd = 0;
            return slow;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

}

node* reverseLL(node* head)
{
    if(head == nullptr || head->next == nullptr) return head;

    node* back = nullptr;
    node* curr = head;
    node* front = head->next;

    while(curr != nullptr)
    {
        curr->next = back;
        back = curr;
        curr = front;
        if(front) front = front->next;
    }
    return back;
}

bool checkPalindrome(node* head)
{
    if(head == nullptr || head->next == nullptr) return true;

    int is_odd = 0;
    node* mid = findMid(head, is_odd);

    if(is_odd)
    {
        node* newHead = reverseLL(mid);
        node* mainHead = head;
        while(mainHead != newHead)
        {
            if(mainHead->data != newHead->data) return false;
            mainHead = mainHead->next;
            newHead = newHead->next;
        }
        return true;
    }
    else
    {
        node* newHead = reverseLL(mid->next);
        node* mainHead = head;
        while(newHead != nullptr)
        {
            if(mainHead->data != newHead->data) return false;
            mainHead = mainHead->next;
            newHead = newHead->next;
        }
        return true;
    }    

    // TC : 2N
    // SC : 1
}

int main()
{
    node* head = createLL(6); 
    cout << checkPalindrome(head);
}