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

vector<vector<int>> levelOrder(node* root)
{
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++)
        {
            node* currentNode = q.front();
            q.pop();
            if(currentNode->left != NULL) q.push(currentNode->left);
            if(currentNode->right != NULL) q.push(currentNode->right);
            level.push_back(currentNode->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main() 
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(5); 
    vector<vector<int>> result = levelOrder(root);
    for(auto innerVec : result)
    {
        for(auto elem : innerVec)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
