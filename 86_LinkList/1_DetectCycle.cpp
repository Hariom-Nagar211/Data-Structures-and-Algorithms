#include<bits/stdc++.h>
using namespace std;

// QUE : Detect a loop or cycle in LinkedList
// best solution : slow and fast pointers
// Link : https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // Changing LL val to -1 and iterating over it to find -1 again
        bool detectCycle = false;
        vector<int> arr;     // preserve original LL
        ListNode* curr = head;
        while(curr)
        {
            if(curr->val == -1e7)
            {
                detectCycle = true;
                break;
            }

            arr.push_back(curr->val);
            curr->val = -1e7;

            curr = curr->next;
        }

        // againg restoring original LL;
        int n = arr.size();
        curr = head;
        for(int i=0; i<n; i++)
        {
            curr->val = arr[i];

            curr = curr->next;
        }
        return detectCycle;

        
    }
};

int main()
{
    node* head = createLL(9);
    node* temp1 = head;
    while(temp1->data != 4) temp1 = temp1->next;
    node* temp2 = head;
    while(temp2->next != nullptr) temp2 = temp2->next;
    temp2->next = temp1;

    cout << DetectLoop(head);


}