#include<bits/stdc++.h>
using namespace std;

// Que: Find the diameter of a BT.

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

// Brute
int max_diameter = 0;
int DiameterOfBT1(node* root)
{
    if(root == NULL) return 0;

    int lh = Max_Depth(root->left);
    int rh = Max_Depth(root->right);

    max_diameter = max(max_diameter, lh+rh);
    Brute(root->left);
    Brute(root->right);
    return max_diameter;

    // TC: n*n
}

// Optimal 
int DiameterOfBT2(node* root, int &maxi)
{
    if(root == NULL) return 0;

    int lh = diameter(root->left, maxi);
    int rh = diameter(root->right, maxi);

    maxi = max(maxi, lh+rh);
    return 1 + max(lh, rh);
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(7);
    root->right->left->left = new node(5);
    root->right->right->right = new node(8);
    root->right->left->left->left = new node(6);
    root->right->right->right->right = new node(9);

    cout << DiameterOfBT1(root) << endl;
    
    int diameter = 0;
    DiameterOfBT2(root, diameter);
    cout << diameter;
}