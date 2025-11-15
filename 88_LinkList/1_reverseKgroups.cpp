
// Link : https://leetcode.com/problems/reverse-nodes-in-k-group/


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
    // Reverse exactly k nodes starting from 'head'
    // Returns {new_head_of_block, new_tail_of_block, pointer_to_next_segment}
    std::tuple<ListNode*, ListNode*, ListNode*> reverseBlock(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        // prev = new head of this block
        // head = new tail (old head)
        // curr = pointer to next segment after this block
        return {prev, head, curr};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        // First, count length
        int n = 0;
        for (ListNode* tmp = head; tmp; tmp = tmp->next) n++;
        if (n < k) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevTail = &dummy;
        ListNode* curr = head;

        while (n >= k) {
            auto [blockHead, blockTail, nextStart] = reverseBlock(curr, k);
            prevTail->next = blockHead;
            blockTail->next = nextStart;

            prevTail = blockTail;
            curr = nextStart;
            n -= k;
        }
        return dummy.next;
    }
};
