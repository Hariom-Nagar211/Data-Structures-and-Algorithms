#include<bits/stdc++.h>
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

void InorderTraversal(node *root, vector<int> &Inorder)
{
    if(root == NULL) return;

    InorderTraversal(root->left, Inorder);
    Inorder.push_back(root->data);
    InorderTraversal(root->right, Inorder);
    return;
}

bool isTwoSum1(node *root, int num)
{
    vector<int> Inorder;
    InorderTraversal(root, Inorder);

    int n = Inorder.size();
    int i = 0;
    int j = n-1;
    while(i < j)
    {
        if(Inorder[i] + Inorder[j] == num) return true;
        else if(Inorder[i] + Inorder[j] < num) i++;
        else j--;
    }
    return false;
}

stack<node *> st; 

node *next()
{
    if(stack.empty()) return NULL;

    node *currNode = st.top();
    st.pop();
    if(currNode->right) pushAll(currNode->right);
    return currNode;
}

node *before()
{
    if(stack.empty()) return NULL;

    node *currNode = st.top();
    st.pop();
    if(currNode->right) pushAll(currNode->right);
    return currNode;
}


bool isTwoSum2(node *root, int num)
{

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


    int num = 2;
    cout << isTwoSum1(root, num);

    // Using BST iterator
}