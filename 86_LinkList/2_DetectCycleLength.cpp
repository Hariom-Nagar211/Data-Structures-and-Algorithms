#include<bits/stdc++.h>
using namespace std;

// QUE : Detect a loop or cycle length in LinkedList
// Explanation Math : https://chatgpt.com/c/68d77758-b92c-8325-887e-1113d666f7c1
// Link: https://leetcode.com/problems/linked-list-cycle-ii/submissions/1783899886/

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
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) break;
        }

        if(!fast || !fast->next) return nullptr;

        ListNode* cycleStart = head;
        while(cycleStart != slow)
        {
            cycleStart = cycleStart->next;
            slow = slow->next;
        }
        return cycleStart;
        
    }
};