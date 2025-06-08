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

int CeilInBST(node *root, int key)
{
    int ceil = -1;
    while(root)
    {
        if(root->data == key)
        {
            ceil = root->data;
            return ceil;
        }

        if(key > root->data) root = root->right;
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;

    // TC: log(2,n)
    // SC: 1
}

int main()
{
    node *root = new node(8);
    root->left = new node(5);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->left->right->left = new node(6);
    root->right = new node(12);
    root->right->left = new node(10);
    root->right->right = new node(14);
    root->right->right->left = new node(13);

    int target = 15;
    CeilInBST(root, target);
}