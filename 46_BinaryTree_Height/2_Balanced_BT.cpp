#include<bits/stdc++.h>
using namespace std;

// Balanced BT : at any node abs(lh - rh) <= 1

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

// Brute Force Solution
bool Balanced_BT_Brute(node* root)
{
    if(root == NULL) return true;

    int ld = Max_Depth(root->left);
    int rd = Max_Depth(root->right);

    if(abs(ld-rd) > 1) return false;

    bool left = Balanced_BT_Brute(root->left);
    bool right = Balanced_BT_Brute(root->right);

    if(!left || !right) return false;

    return true;

    // TC: n
    // SC: logn(if balanced) or n(if completely unbalanced)[except the max_depth function]
}

// Optimal Solution
int dfsHeight(node* root) 
{
    if(root == NULL) return 0;

    int lh = dfsHeight(root->left);
    int rh = dfsHeight(root->right);

    if(lh == -1 || rh == -1) return -1;
    if(abs(lh-rh) > 1) return -1;

    return 1 + max(lh, rh);

}


bool Balanced_BT_Optimal(node* root)
{
    if(dfsHeight(root) == -1) return false;
    else return true;
}

int main()
{
    node* root = new node(3);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);

    cout << Balanced_BT_Brute(root) << endl;
    cout << Balanced_BT_Optimal(root);



}
