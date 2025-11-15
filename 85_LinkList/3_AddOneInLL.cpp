
// Link : https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  private:
    Node* reverseLL(Node* head)
    {
        Node* prev = nullptr;
        Node* curr = head;
        while(curr)
        {
            Node* temp = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
  public:
    Node* addOne(Node* head) {
        // Your Code here
        
        Node* new_head = reverseLL(head);
        
        Node* curr = new_head;
        int carry = 0;
        
        int val = 1 + carry + curr->data;
        int digit = (val)%10;
        if(val > 9) carry = 1;
        else carry = 0;
        curr->data = digit;
        curr = curr->next;
        while(curr)
        {
            
            int val = carry + curr->data;
            int digit = (carry + curr->data)%10;
            if(val > 9) carry = 1;
            else carry = 0;
                
            curr->data = digit;
            
            curr = curr->next;
        }
        
        if(carry)
        {
            Node* last = new Node(carry);
            
            head->next = last;
            
        }
        
        return reverseLL(new_head);
        
        
        
    }
};