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

void mark_parent_pointers(node* root, unordered_map<node* ,node*> &parent_track)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            node* curr = q.front();
            q.pop();
            if(curr->left)
            {
                q.push(curr->left);
                parent_track[curr->left] = curr;
            }
            if(curr->right)
            {
                q.push(curr->right);
                parent_track[curr->right] = curr;
            }
        }
    }
}

int min_time_to_burn(node* root, node* target)
{
    unordered_map<node* ,node*> parent_track;
    mark_parent_pointers(root, parent_track);

    unordered_map<node* , bool> visited;
    queue<node*> q;
    q.push(target);
    visited[target] = true;
    int cnt = -2;
    
    while(!q.empty())
    {
        cnt++;
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            node* curr = q.front();
            q.pop();

            if(curr->left)
            {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right)
            {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(parent_track[curr] && !visited[parent_track[curr]])
            {
                q.push(parent_track[curr]);
                visited[parent_track[curr]] = true;
            }
        }
    }
    return cnt;

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

    node* target = root->left->right->right;

    cout << min_time_to_burn(root, target);

}    