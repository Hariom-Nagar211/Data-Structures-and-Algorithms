#include<bits/stdc++.h>
using namespace std;

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

bool Optimal(node* root, vector<int> &arr, int t)
{
    if(!root) return false;

    arr.push_back(root->data);

    if(root->data == t) return true;

    if(Optimal(root->left, arr, t) || Optimal(root->right, arr, t)) return true;

    arr.pop_back();
    return false;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);
    root->right = new node(3);

    vector<int> ans;
    Optimal(root, ans, 7);

    for(auto it : ans)
    {
        cout << it << " ";
    }
    
}