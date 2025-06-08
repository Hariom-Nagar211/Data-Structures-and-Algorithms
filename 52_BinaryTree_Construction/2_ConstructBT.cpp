#include <bits/stdc++.h>
using namespace std;

// QUE : Construct a unique binary tree from given inorder and postorder traversal.

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

node* buildTree(vector<int> postorder, int postStart, int postEnd, 
               vector<int> inorder, int inStart, int inEnd, map<int, int> inMap)
{
    if(postStart > postEnd  || inStart > inEnd) return nullptr;

    node* root = new node(postorder[postEnd]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(postorder, postStart , postStart + numsLeft-1,
                           inorder, inStart, inRoot-1, inMap);
    root->right = buildTree(postorder, postStart + numsLeft , postEnd-1,
                            inorder, inRoot + 1, inEnd, inMap);
    
    return root;
}               

node* ConstructBT(vector<int> &postorder, vector<int> &inorder)
{
    map<int, int> inMap;

    for(int i=0; i<inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    node* root = buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);

    return root;

    // Logic : Breaking the problem into small problems and using recursion
}

int main()
{
    vector<int> postorder = {40,50,20,60,30,10}; // left, right, root
    vector<int> inorder = {40,20,50,10,60,30};   // left, root, right

    node* root = ConstructBT(postorder, inorder);
}