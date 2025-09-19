#include<bits/stdc++.h>
using namespace std;

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

void ChildrenSumProperty(node* &root)
{
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) return;

    if((root->left->data + root->right->data) < (root->data))
    {
        root->left->data = root->data;
        root->right->data = root->data;
    }
    else
    {
        root->data = root->left->data + root->right->data;
    }   

    ChildrenSumProperty(root->left);
    ChildrenSumProperty(root->right);
    root->data = root->left->data + root->right->data;
}

int main()
{
    node* root = new node(50);
    root->left = new node(7);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(1);
    root->right->right = new node(30);

    ChildrenSumProperty(root);

    cout << root->data;


}