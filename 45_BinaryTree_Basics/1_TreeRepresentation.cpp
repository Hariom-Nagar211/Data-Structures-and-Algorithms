#include<bits/stdc++.h>
using namespace std;

// structure is used to define our own dataType
struct node 
{
    int data;
    node* left; // left store a pointer to node dataType which is struct dataType
    node* right; // struct node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


int main()
{
    // struct node* root: Declares root as a pointer to a node.
    // new node(1): Allocates a new node with data set to 1 and returns a pointer to that node.
    // root = new node(1): Assigns the pointer (the memory address of the new node) to root.
    node* root = new node(1);
    // root->left:
    // root is a pointer to a node object, so root holds the memory address of the node that is dynamically allocated by new node(1).
    // root->left accesses the left pointer of the node that root points to.
    root->left = new node(2);
    root->right = new node(3);

}