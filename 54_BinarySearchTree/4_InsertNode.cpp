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

node *InsertNodeInBST(node *root, int value)
{
    node *currNode = root;
    while(true)
    {
        if(currNode->data > value)
        {
            if(currNode->left) currNode = currNode->left;
            else
            {
                currNode->left = new node(value);
                return root;
            }
        }
        else
        {
            if(currNode->right) currNode = currNode->right;
            else
            {
                currNode->right = new node(value);
                return root;
            }
        }
    }
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

    int value = 11;
    InsertNodeInBST(root, value);
    cout << root->right->left->right->data;

}