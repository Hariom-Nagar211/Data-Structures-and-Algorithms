#include<bits/stdc++.h>
using namespace std;

// QUE : https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return head;

        ListNode* even_head = head->next;

        ListNode* odd_node = head;
        ListNode* even_node = head->next;
        while(odd_node && even_node)
        {
            if(odd_node->next) odd_node->next = odd_node->next->next;
            if(even_node->next) even_node->next = even_node->next->next;

            odd_node = odd_node->next;
            even_node = even_node->next;
        }
        
        ListNode* odd_tail = head;
        while(odd_tail->next != nullptr) odd_tail = odd_tail->next;

        odd_tail->next = even_head;

        return head;

        
    }
};

