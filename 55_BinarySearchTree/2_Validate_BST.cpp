#include <bits/stdc++.h>
using namespace std;

// Logic : Inorder of BST is always sorted

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

void Inorder(node *root, int &ans, int &temp)
{
    if (root == NULL)
        return;

    Inorder(root->left, ans, temp);
    if (temp >= root->data)
        ans = 0;
    temp = root->data;
    Inorder(root->right, ans, temp);
}

bool ValidateBST1(node *root)
{
    if (root == NULL)
        return true;
    int ans = 1;
    int temp = INT_MIN;
    Inorder(root, ans, temp);
    return ans;
}

bool Helper(node *root, long int minVal, long int maxVal)
{
    if (root == NULL)
        return true;
    if (root->data >= maxVal || root->data <= minVal)
        return false;

    return Helper(root->left, minVal, root->data) && Helper(root->right, root->data, maxVal);
}

bool ValidateBST2(node *root)
{
    return Helper(root, INT_MIN, INT_MAX);
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

    cout << ValidateBST1(root) << endl;
    cout << ValidateBST2(root);
}