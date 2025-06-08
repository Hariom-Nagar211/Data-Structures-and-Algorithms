#include <bits/stdc++.h>
using namespace std;

// Introduction to Binary Search Trees : 
// https://takeuforward.org/binary-search-tree/introduction-to-binary-search-trees/

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

node *SearchInBST(node *root, int target)
{
    node *currNode = root;

    while (currNode != NULL)
    {
        if (currNode->data == target)
            return currNode;

        else if (currNode->data < target)
            currNode = currNode->right;

        else
            currNode = currNode->left;
    }
    return NULL;

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

    int target = 10;
    node *ans = SearchInBST(root, target);
    cout << ans->data;
}