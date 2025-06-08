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

void preorder(node* root) // NLR
{
    if(root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right); 

}

void inorder(node* root) // LNR
{
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

void postorder(node* root) // LRN
{
    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    
}

int main()
{
    node* root = new node(1);    //                         1
    root->left = new node(2);   //                  2              3
    root->right = new node(3);  //              4       5
    root->left->left = new node(4);//         6
    root->left->right = new node(5);
    root->left->left->left = new node(6);

    preorder(root); // Root → Left → Right
    cout << endl;
    inorder(root); // Left → Root → Right
    cout << endl;
    postorder(root); // Left → Right → Root
    
    
}