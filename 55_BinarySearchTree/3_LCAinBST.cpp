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

void LCAinBST1(node *root, int a, int b, int &ans)
{
    if(root == NULL) return;

    if(a < root->data && b > root->data)
    {
        ans = root->data;
        return;
    } 
    else if(a < root->data && b < root->data) LCAinBST1(root->left, a, b, ans);
    else LCAinBST1(root->right, a, b, ans);
    
}

int LCAinBST2(node *root, int a, int b)
{
    if(root == NULL) return -1;

    while(root)
    {
        if(a < root->data && b > root->data) return root->data;
        else if(a < root->data && b < root->data) root = root->left;
        else root = root->right;
    }
    return -1;
}

int main()
{
    node *root = new node(15);
    root->left = new node(11);
    root->left->left = new node(7);
    root->left->left->right = new node(9);
    root->left->right = new node(13);
    root->right = new node(26);
    root->right->left = new node(21);
    root->right->right = new node(30);

    int ans = -1;
    int a = 9;
    int b = 13;
    LCAinBST1(root, a, b, ans);
    cout << ans << endl;

    cout << LCAinBST2(root, a, b);
    
}