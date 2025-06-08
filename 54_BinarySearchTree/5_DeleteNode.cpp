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

node *findLastRight(node *root)
{
    if(root->right == NULL) return root;
    return findLastRight(root->right);
}

node *Helper(node *root)
{
    if(root->left == NULL) return root->right;
    if(root->right == NULL) return root->left;

    node *rightChild = root->right;
    node *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;

}

node *DeleteNode(node *root, int value)
{
    if(root == NULL) return root;

    if(root->data == value) return Helper(root);

    node *dummy = root;
    while(root != NULL)
    {
        if(root->data > value)
        {
            if(root->left && root->left->data == value)
            {
                root->left = Helper(root->left);
                break;

            }
            else root = root->left;
        }
        else
        {
            if(root->right && root->right->data == value) 
            {
                root->right = Helper(root->right);
                break;
            }
            else root = root->right;
        }
    }
    return dummy;
}

int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right = new node(6);
    root->right->right = new node(7);

    int value = 3;
    DeleteNode(root, value);
    cout << root->left->data;


}