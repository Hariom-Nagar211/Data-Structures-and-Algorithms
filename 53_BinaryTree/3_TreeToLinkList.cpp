#include <bits/stdc++.h>
using namespace std;

// Que : Convert BT into LL(inorder)

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* Brute(node *root, node* prev)
{
    if(root == nullptr) return nullptr;

    Brute(root->right);
    Brute(root->left);

    root->right = prev;
    root->left = nullptr;

    prev = root;

    // Logic : Right Left Root
    // TC : N
    // SC : N

}

node *TreeToLinkList(node *root)
{
    stack<node *> st;

    st.push(root);
    while (!st.empty())
    {
        node *currNode = st.top();
        st.pop();

        if(currNode->right) 
        {
            st.push(currNode->right);
            currNode->right = NULL;
        }
        if(currNode->left) st.push(currNode->left);
        root->left = currNode;
        root = currNode;
    }
    return root;

    // TC : N
    // SC : N

}

// Do the third approach by yourself(TC : N, SC : 1)

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->right = new node(6);
    root->right->right->left = new node(7);

    TreeToLinkList(root);
    cout << root->right->data;



}