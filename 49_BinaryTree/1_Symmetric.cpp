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

bool Optimal1(node* root)
{
    queue<node*> q1;
    queue<node*> q2;

    q1.push(root->left);
    q2.push(root->right);
    while(!q1.empty() && !q2.empty())
    {
        node* currNode1 = q1.front();
        node* currNode2 = q2.front();
        q1.pop();
        q2.pop();

        if(q1.size() != q2.size()) return false;
        if(currNode1->data != currNode2->data) return false;
        if(currNode1->left) q1.push(currNode1->left);
        if(currNode2->right) q2.push(currNode2->right);
        if(currNode1->right) q1.push(currNode1->right);
        if(currNode2->left) q2.push(currNode2->left);
    }

    return true;
}

bool recursion(node* node1, node* node2)
{
    if(node1 == NULL || node2 == NULL) return node1==node2;

    if(node1->data != node2->data) return false;

    return recursion(node1->left, node2->right) && 
           recursion(node1->right, node2->left); 
}

bool Optimal2(node* root)
{
    if(!root) return true;
    return recursion(root->left, root->right);

}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);
    root->right->right->left = new node(3);

    cout << Optimal1(root) << endl;
    cout << Optimal2(root);


}