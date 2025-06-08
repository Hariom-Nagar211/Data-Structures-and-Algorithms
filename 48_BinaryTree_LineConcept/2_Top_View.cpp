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

vector<int> Optimal(node* root)
{
    if(!root) return {};

    vector<int> ans;
    map<int, int> mpp;  // {VerticalLine, element};
    queue<pair<node*, int>> q; // {*element, VerticalLine}

    q.push({root, 0});
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        node* currNode = it.first;
        int line = it.second;
        if(mpp.find(line) == mpp.end()) mpp[line] = currNode->data;
        if(currNode->left) q.push({currNode->left, line-1});
        if(currNode->right) q.push({currNode->right, line+1});
    }

    for(auto it : mpp) ans.push_back(it.second);
    return ans;

    // Logic : Line Concept
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(21);
    root->left->right = new node(12);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(7);
    root->right->left->left = new node(5);
    root->right->right->right = new node(8);
    root->right->left->left->left = new node(6);
    root->right->right->right->right = new node(9);

    vector<int> ans = Optimal(root);

    for(auto it : ans) cout << it << " ";
}