#include<bits/stdc++.h>
using namespace std;

// QUE : Find all Pairs with given Sum in sorted DLL
// Link:  https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        
        Node* first = head;
        Node* last = head;
        while(last->next) last = last->next;
        
        vector<pair<int, int>> pairs;
        while(first != last)
        {
            int val = first->data + last->data;
            
            if(val == target)
            {
                pairs.push_back({first->data, last->data});
                
                if(first->next == last) break;
                
                first = first->next;
                last = last->prev;
                
                
            }
            else if(val > target)
            {
                last = last->prev;
            }
            else first = first->next;
        }
        return pairs;
        
    }
};