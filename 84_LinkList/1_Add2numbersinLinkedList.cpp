#include<bits/stdc++.h>
using namespace std;

// QUE : You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode((l1->val + l2->val)%10);
        ListNode* curr = head;

        int carry = (l1->val + l2->val)/10;

        l1 = l1->next;
        l2 = l2->next;

        while(l1 && l2)
        {
            int val = l1->val + l2->val;

            int digit = (val%10 + carry)%10;
            carry = (val+carry)/10;

            ListNode* new_node = new ListNode(digit);

            curr->next = new_node;
            curr = new_node;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            int digit = (l1->val + carry)%10;
            carry = (l1->val+carry)/10;

            ListNode* new_node = new ListNode(digit);

            curr->next = new_node;
            curr = new_node;
            l1 = l1->next;
        }
        while(l2)
        {
            int digit = (l2->val + carry)%10;
            carry = (l2->val+carry)/10;

            ListNode* new_node = new ListNode(digit);

            curr->next = new_node;
            curr = new_node;
            l2 = l2->next;
        }

        if(carry)
        {
            ListNode* new_node = new ListNode(carry);
            curr->next = new_node;
        }

        return head;
    }
};