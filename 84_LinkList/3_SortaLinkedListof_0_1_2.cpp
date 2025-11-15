
// Link : https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(!head) return head;
        
        vector<int> cnt(3, 0);
        Node* curr = head;
        while(curr)
        {
            cnt[curr->data]++;
            curr = curr->next;
        }
        
        curr = head;
        int idx = 0;
        while(curr)
        {
            while(cnt[idx] <= 0) idx++;
            
            curr->data = idx;
            cnt[idx]--;
            
            curr = curr->next;
        }
        return head;
    }
};