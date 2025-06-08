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

node* build(vector<int> &preorder, int &i, int &bound) 
{
    if(i > preorder.size() || preorder[i] > bound) return nullptr;
    node* root = new node(preorder[i++]);
    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, bound);
    return root;
}

node* bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return build(preorder, i, INT_MAX);
}

int main()
{
    vector<int> preorder = {8,5,1,7,10,12};
    node* root;
    ConstructBT(preorder);
}