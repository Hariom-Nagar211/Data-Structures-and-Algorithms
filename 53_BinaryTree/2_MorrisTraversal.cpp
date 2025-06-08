#include <bits/stdc++.h>
using namespace std;

// The Morris Traversal is an efficient tree traversal algorithm that eliminates 
// the need for recursion or a stack while maintaining 𝑂(𝑛) O(n) time complexity. 
// It achieves this by temporarily modifying the tree's structure to create a 
// threaded binary tree.

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

vector<int> getInorder(node *root)
{
    vector<int> inorder;

    node *currNode = root;
    while (currNode != nullptr)
    {
        if(currNode->left == nullptr)
        {
            inorder.push_back(currNode->data);
            currNode = currNode->right;
        }
        else
        {
            node *prev = currNode->left;
            while(prev->right != nullptr && prev->right != currNode)
            {
                prev = prev->right;
            }

            if(prev->right == nullptr)
            {
                prev->right = currNode;
                currNode = currNode->left;
            }
            else
            {
                prev->right = nullptr;
                inorder.push_back(currNode->data);
                currNode = currNode->right;
            }
        }
    }
    return inorder;

    // TC: n
    // SC: 1
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->right = new node(6);
    root->right = new node(3);

    vector<int> ans = getInorder(root);

    for(auto it : ans)
    {
        cout << it << " ";
    }

}