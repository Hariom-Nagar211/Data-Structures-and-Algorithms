#include<bits/stdc++.h>
using namespace std;

// QUE : Find all Pairs with given Sum in sorted DLL
// Link:  https://tinyurl.com/y4xca7e5

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

vector<pair<int, int>> findPairs(node* head, int k)
{
    vector<pair<int, int>> pairs;

    // i points first element and j points last element of DLL
    node* i = head;
    node* j = head;
    while(j->next != nullptr) j = j->next;

    // Two Pointers apporoach
    while(i < j)
    {
        if((i->data) + (j->data) == k) 
        {
            pairs.push_back({i->data, j->data});
            i = i->next;
            j = j->back;
        }
        else if((i->data) + (j->data) < k) i = i->next;
        else j = j->back;
    }

    return pairs;
}