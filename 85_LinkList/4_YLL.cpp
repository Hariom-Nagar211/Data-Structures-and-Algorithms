
// Link : https://leetcode.com/problems/intersection-of-two-linked-lists/


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // changing val of LL1 to -1 and storing orignal valuse in arr
        ListNode* curr = headA;
        vector<int> arr;
        while(curr)
        {
            arr.push_back(curr->val);
            curr->val = -1;
            curr = curr->next;
        }

        // matching LL2 val with LL1 until we fing -1(inter point)
        curr = headB;
        ListNode* inter = nullptr;
        while(curr)
        {
            if(curr->val == -1) 
            {
                inter = curr;
                break;
            }
            curr = curr->next;
        }

        // again restorin LL1 to it's original values
        curr = headA;
        int i = 0;
        while(curr)
        {
            curr->val = arr[i];

            curr = curr->next;
            i++;
        }
        return inter;
        
    }
};