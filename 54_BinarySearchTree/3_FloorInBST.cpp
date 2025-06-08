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
        left = NULL;
        right = NULL;
    }
};

int FloorInBST(node *root, int key)
{
    int floor = -1;

    while(root)
    {
        if(root->data == key) return key;
        else if(root->data > key) root = root->left;
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;

    // TC: log(2,n)
    // SC: 1
}

int main()
{
    node *root = new node(8);
    root->left = new node(5);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->left->right->left = new node(6);
    root->right = new node(12);
    root->right->left = new node(10);
    root->right->right = new node(14);
    root->right->right->left = new node(13);

    int key = 11;
    int ans = FloorInBST(root, key);
    cout << ans;

}