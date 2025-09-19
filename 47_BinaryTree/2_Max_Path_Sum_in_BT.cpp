#include<bits/stdc++.h>
using namespace std;

// Que: return the maximum sum of a path in BT.

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

int maxPath(node* root, int &maxSum)
{
    if(root == NULL) return 0;

    int ls = max(0, maxPath(root->left, maxSum));
    int rs = max(0, maxPath(root->right, maxSum));
    int cs = root->data;

    maxSum = max(maxSum, ls+rs+cs);

    return cs + max(ls, rs);

}

int Optimal(node* root)
{
    int maxSum = INT_MIN;
    maxPath(root, maxSum);
    return maxSum;

    // TC: n
}

int main()
{
    node* root = new node(10);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);

    cout << Optimal(root);
}

