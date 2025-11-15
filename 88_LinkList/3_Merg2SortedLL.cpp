
// Link : https://leetcode.com/problems/merge-two-sorted-lists/

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
private:
    ListNode* merg(ListNode* head1, ListNode* head2)
    {
        ListNode* new_head = nullptr;
        if(head1->val <= head2->val) new_head = head1;
        else new_head = head2;

        while(head1 && head2)
        {
            if(head1->val <= head2->val)
            {
                ListNode* prev = nullptr;
                while(head1 && head1->val <= head2->val)
                {
                    prev = head1;
                    head1 = head1->next;
                }

                prev->next = head2;
            }
            else
            {
                ListNode* prev = nullptr;
                while(head2 && head2->val <= head1->val)
                {
                    prev = head2;
                    head2 = head2->next;
                }

                prev->next = head1;
            }
        }
        return new_head;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(!list1) return list2;
        else if(!list2) return list1;

        return merg(list1, list2);
        
    }
};