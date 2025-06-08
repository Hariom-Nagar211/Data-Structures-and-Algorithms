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

// Approach 1 : Inorder traversal, Stre Inorder, Binary Search the Target.
// Approach 2 : Inorder Traversal, return the first value you encounter,
//              which is greater than given value.
// Approach 3 : Search in BST(code given below)

node *getInorderSuccessor(node *root, int value)
{
    node *successor = NULL;
    while(root != NULL)
    {
        if(value >= root->data)
        {
            root = root->right;
        } 
        else
        {
            successor = root;
            root = root->left;
        }  
    }
    return successor;
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

    int value = 3;
    cout << getInorderSuccessor(root, value)->data;




}