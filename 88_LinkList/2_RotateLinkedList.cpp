
// Link : https://leetcode.com/problems/rotate-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next) return head;

        int n = 0;
        ListNode* curr = head;
        while(curr)
        {
            n++;
            curr = curr->next;
        }

        k = k%n;
        if(k == 0) return head;

        // breaking the LL from (n-k)th node and attaching last node to first
        int last_node = n - k - 1;
        curr = head;
        while(last_node--) curr = curr->next;

        ListNode* new_head = curr->next;
        curr->next = nullptr;
        ListNode* prev = nullptr;
        curr = new_head;
        while(curr)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = head;
        
        return new_head;
        
        
        
    }
};