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

void Inorder(node *root, int k, int &ans, int &cnt)
{
    if(root->left)Inorder(root->left, k, ans, cnt);
    cnt++;
    if(cnt == k) ans = root->data;
    if(root->right) Inorder(root->right, k, ans, cnt);
    return;
}

int KthSmallestElement(node *root, int k)
{
    int ans = -1;
    int cnt = 0;
    Inorder(root, k, ans, cnt);
    return ans;

    // Logic : The inorder of any BST is always in sorted order.
}

int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->left->left = new node(1);
    root->left->left->right = new node(2);
    root->left->right = new node(4);
    root->right = new node(7);
    root->right->left = new node(6);
    root->right->right = new node(8);

    int k = 3;
    cout << KthSmallestElement(root, k);

}