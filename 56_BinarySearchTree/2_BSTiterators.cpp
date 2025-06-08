#include <bits/stdc++.h>
using namespace std;

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

// Note : You are not allowed to store inorder

stack<node *> st;

void PushAll(node *root)
{
    while(root != NULL)
    {
        st.push(root);
        root = root->left;
    }
}

void BSTiterator(node *root)
{
    PushAll(root);
}

bool hashNext()
{
    return !st.empty();
}

node *next()
{
    if(st.empty()) return NULL;
    
    node *currNode = st.top();
    st.pop();
    if(currNode->right) PushAll(currNode->right);
    return currNode;
}

int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->left->left->left = new node(1);
    root->right = new node(7);
    root->right->left = new node(6);
    root->right->right = new node(9);
    root->right->right->left = new node(8);
    root->right->right->right = new node(10);

    
    BSTiterator(root);
    cout << next()->data << " ";
    cout << next()->data << " ";
    cout << hashNext() << " ";

}




