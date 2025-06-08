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
        left = nullptr;
        right = nullptr;
    }
};

int cnt_left_height(node* root)
{
    int cnt = 0;
    while(root)
    {
        cnt++;
        root = root->left;
    }
    return cnt;
}

int cnt_right_height(node* root)
{
    int cnt = 0;
    while(root)
    {
        cnt++;
        root = root->right;
    }
    return cnt;
}

int cnt_nodes_of_CBT(node* root)
{
    if(root == NULL) return 0;

    int lh = cnt_left_height(root);
    int rh = cnt_right_height(root);

    if(lh == rh) return (pow(2, lh) - 1);

    return 1 + cnt_nodes_of_CBT(root->left) + cnt_nodes_of_CBT(root->right);

    // TC: [log(n)]^2
    // SC: log(n)
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right = new node(5);
    root->left->right->left = new node(10);
    root->left->right->right = new node(11);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << cnt_nodes_of_CBT(root);
}