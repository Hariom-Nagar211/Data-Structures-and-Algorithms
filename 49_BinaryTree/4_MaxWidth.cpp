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

int MaxWidth(node* root)
{
    if(root == NULL) return 0;

    queue<pair<node*, int>> q;
    int width = 0;
    int max_width = 0;

    q.push({root, 0});
    while(!q.empty())
    {
        int size = q.size();
        int mini = q.front().second;
        int fst, lst; 
        for(int i=0; i<size; i++)
        {
            node* currNode = q.front().first;
            int currIndex = q.front().second - mini;
            q.pop();
            if(currNode->left) q.push({currNode->left, currIndex*2+1});
            if(currNode->right) q.push({currNode->right, currIndex*2+2});

            if(i == 0) fst = currIndex;
            if(i == size-1) lst = currIndex;

        }
        width = (lst - fst + 1);
        max_width = max(width, max_width);
    }
    return max_width;

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
    root->right->left = new node(8);
    root->right->right = new node(9);

    cout << MaxWidth(root);
}