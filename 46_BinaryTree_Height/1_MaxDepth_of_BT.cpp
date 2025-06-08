#include<bits/stdc++.h>
using namespace std;

// Que: Return the maximum depth of a binary tree.

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }

};

int Max_Depth_of_BT(node* root) 
{
    if (root == NULL) return 0; 

    stack<pair<node*, int>> st; 
    int max_depth = 0;

    st.push({root, 1}); 
    while (!st.empty()) 
    {
        node* current_node = st.top().first; 
        int current_depth = st.top().second; 
        st.pop(); 

       
        max_depth = max(current_depth, max_depth);

        
        if (current_node->right != NULL) 
        {
            st.push({current_node->right, current_depth + 1});
        }
        if (current_node->left != NULL) 
        {
            st.push({current_node->left, current_depth + 1});
        }
    }

    return max_depth;
}

// Recursive Approach
int Max_Depth(node* root) 
{
    if(root == NULL) return 0;

    int lh = Max_Depth(root->left);
    int rh = Max_Depth(root->right);

    return 1 + max(lh, rh);

    // TC: n
    // SC: height of the tree(space is used by the call stack due to recursion.)

}


int main()
{
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->right->left = new node(4);
    root->right->right = new node(6);

    root->right->left->left = new node(5);

    cout << Max_Depth_of_BT(root) << endl;
    cout << Max_Depth(root);

}