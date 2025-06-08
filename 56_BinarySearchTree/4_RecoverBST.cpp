#include<bits/stdc++.h>
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

stack<node *> st1;
stack<node *> st2;

void PushLeft(node *root)
{
    if(root == NULL) return;

    st1.push(root->left);
    root = root->left;
    PushLeft(root);
}

node *next()
{
    if(st1.empty()) return NULL;

    node *currNode = st1.top();
    st1.pop();
    if(currNode->right) PushLeft(currNode->right);
    return currNode;
}

node *RecoverBST(node *root)
{
    node* i1;
    node *i2;
    node *temp1 = NULL;
    node *temp2 = NULL;
    node *extra1;
    node *extra2;

    while(true)
    {
        i1 = next();
        i2 = next();

        if(i1->data > i2->data)
        {
            if(temp1 == NULL)
            {
                temp1 = i1;
                extra1 = i2;
            }
            else
            {
                temp2 = i1;
                extra2 = i2;
            } 
        }
        if(temp2 != NULL)
        {
            node* temp;
            temp->data = temp1->data;
            temp1->data = temp2->data;
            temp2->data = temp->data;
            break;
        }
        else
        {
            node* temp;
            temp->data = temp1->data;
            temp1->data = extra1->data;
            extra1->data = temp->data;
            break;
        } 

    }
}

int main()
{
    node *root = new node(5);
    root->left = new node(1); // 3
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->left->left->left = new node(3); // 1
    root->right = new node(7);
    root->right->left = new node(6);
    root->right->right = new node(9);
    root->right->right->left = new node(8);
    root->right->right->right = new node(10);

    RecoverBST(root);

    cout << root->data;
    cout << root->left->data;
    cout << root->left->left->data;
    cout << root->left->right->data;
    cout << root->left->left->left->data;
    cout << root->right->data;
    cout << root->right->left->data;
    cout << root->right->right->data;
    cout << root->right->right->left->data;
    cout << root->right->right->right->data; 

}