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

// Note : You can try left view by Yourself the Concept is Same

vector<int> Optimal1(node* root)
{
    vector<int> ans;

    if(root == NULL) return ans;

    queue<node*> q;

    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        int element = -1;
        for(int i=0; i<size; i++)
        {
            node* currNode = q.front();
            q.pop();
            element = currNode->data;
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        ans.push_back(element);
    }

    return ans;

    // Logic : Reverse Recursive Preorder Traversal 
}

void inv_pre_order_trversal(node* root, int level, vector<int> &res)
{
    if(!root) return;

    if(level == res.size()) res.push_back(root->data);
    inv_pre_order_trversal(root->right, level+1, res);
    inv_pre_order_trversal(root->left, level+1, res);
    
}

vector<int> Optimal2(node* root)
{
    vector<int> res;
    int level = 0;
    inv_pre_order_trversal(root, level, res);
    return res;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> ans1 = Optimal1(root);
    vector<int> ans2 = Optimal2(root);

    for(auto it : ans1)
    {
        cout << it << " ";
    }
    cout << endl;
    for(auto it : ans2)
    {
        cout << it << " ";
    }





}