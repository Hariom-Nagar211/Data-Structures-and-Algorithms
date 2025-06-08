#include <bits/stdc++.h>
using namespace std;

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

void mark_parent_pointers(node *root, unordered_map<node *, node *> &parent_track)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node* curr_node = q.front();
            q.pop();
            if(curr_node->left)
            {
                parent_track[curr_node->left] = curr_node;
                q.push(curr_node->left);
            }
            if(curr_node->right)
            {
                parent_track[curr_node->right] = curr_node;
                q.push(curr_node->right);
            } 
        }
    }
}

vector<int> NodesAtDistanceK(node *root, node* target, int k)
{
    unordered_map<node *, node *> parent_track;
    mark_parent_pointers(root, parent_track);

    queue<node*> q;
    unordered_map<node* , bool> visited;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while(!q.empty())
    {
        int size = q.size();
        if(curr_level++ == k) break;
        for(int i=0; i<size; i++)
        {
            node* curr_node = q.front();
            q.pop();
            if(curr_node->left && !visited[curr_node->left])
            {
                q.push(curr_node->left);
                visited[curr_node->left] = true;
            }
            if(curr_node->right && !visited[curr_node->right])
            {
                q.push(curr_node->right);
                visited[curr_node->right] = true;
            }
            if(parent_track[curr_node] && !visited[parent_track[curr_node]])
            {
                q.push(parent_track[curr_node]);
                visited[parent_track[curr_node]] = true;
            }
        }
    }
    vector<int> res;
    while(!q.empty())
    {
        res.push_back(q.front()->data);
        q.pop();
    }
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
    root->left->right->right = new node(7);
    root->right->left = new node(8);
    root->right->right = new node(9);

    int k = 2;
    node* target = root->left;

    vector<int> res = NodesAtDistanceK(root ,target ,k);

    for(auto it : res)
    {
        cout << it << " ";
    }


}
