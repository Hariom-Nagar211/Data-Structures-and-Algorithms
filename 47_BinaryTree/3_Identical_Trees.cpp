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

int compairTree(node* root1, node* root2, int &flag)
{
    if(root1 != NULL && root2 == NULL)
    {
         flag = 0;
         return 1;
    }
    if(root1 == NULL && root2 != NULL)
    {
        flag = 0;
        return 1;
    } 
    if(root1 == NULL || root2 == NULL) return 1;
    
    if(root1->data == root2->data)
    {
        compairTree(root1->left, root2->left, flag);
        compairTree(root1->right, root2->right, flag);
    }
    else
    {
        flag = 0;
    }
    
}

bool Optimal1(node* root1, node* root2)
{
    int flag = 1;
    compairTree(root1, root2, flag);
    if(flag == 0) return false;
    else return true;
}

int main()
{
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->right->right = new node(5);

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->right->right = new node(5);

    cout << Optimal1(root1, root2);


}