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

// Vertical Order Traversal in Binary Tree
vector<vector<int>> VOT_Brute(node* root)
{
    if(root == nullptr) return {};

    queue<pair<node* , pair<int, int>>> q;   // {*element, {vertical,level}} 
    // map : Store Values in Ascending Sorted Order
    // set : Unique Elements, Sotred in Asending Order
    // multiset : Can Contain Duplicate Elements, Sotred in Asending Order
    map<int, map<int, multiset<int>>> nodes; // {verticlal, {level,elements}} 
    
    // Preorder Traversal
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        node* currNode = p.first;
        int x = p.second.first , y = p.second.second; // x->vertical, y->level

        nodes[x][y].insert(currNode->data);
        if(currNode->left) q.push({currNode->left, {x-1, y+1}});
        if(currNode->right) q.push({currNode->right, {x+1, y+1}});
    }

    vector<vector<int>> ans;
    for(auto p : nodes)
    {
        vector<int> col;
        for(auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;

    // Logic : Line Concept
    // TC : NlogN
    // SC : N
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

    vector<vector<int>> ans = VOT_Brute(root);

    for(auto it : ans)
    {
        for(auto itt : it)
        {
            cout << itt << " ";
        }
        cout << endl;
    }


}