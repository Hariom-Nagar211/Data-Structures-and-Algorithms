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

void f(node* &temp1, node* &temp2, vector<int> &v1, vector<int> &v2)
{
    while(temp1->left != NULL || temp1->right != NULL)
    {
        if(temp1->left != NULL) 
        {
            v1.push_back(temp1->left->data);
            temp1 = temp1->left;
            f(temp1, temp2, v1, v2);
        }
        else
        {
            v1.push_back(temp1->right->data);
            temp1 = temp1->right;
            f(temp1, temp2, v1, v2);
        }
    }

    // while(temp2->left != NULL || temp2->right != NULL)
    // {
    //     if(temp2->right != NULL) 
    //     {
    //         v2.push_back(temp1->right->data);
    //         temp1 = temp1->right;
    //         f(temp1, temp2, v1, v2);
    //     }
    //     else
    //     {
    //         v2.push_back(temp1->left->data);
    //         temp1 = temp1->left;
    //         f(temp1, temp2, v1, v2);
    //     }
    }

    while(temp2->left != NULL || temp2->right != NULL)
    {
        if(temp2->left != NULL)
        {
            node* temp = temp2->left; 
            while(temp->left != NULL || temp->right != NULL)
            {
                if(temp->left != NULL)temp = temp->left;
                if(temp->right != NULL)temp = temp->right;
            }
            v1.push_back(temp->data);
        }

        if(temp2->right != NULL) 
        {
            v2.push_back(temp2->right->data);
            temp2 = temp2->right;
            f(temp1, temp2, v1, v2);
        }
        else
        {
            v1.push_back(temp2->left->data);
            temp2 = temp2->left;
            f(temp1, temp2, v1, v2);
        }
        
    }
}

void Brute(node* root)
{
    vector<int> v1;
    vector<int> v2;
    node* temp1 = root->left;
    v1.push_back(root->data);
    v1.push_back(temp1->data);
    
    node* temp2 = root->right;
    v2.push_back(temp2->data);

    f(temp1, temp2, v1, v2);
    

    reverse(v2.begin(), v2.end());
    v1.insert(v1.end(), v2.begin(), v2.end());

    for(auto it : v1)
    {
        cout << it << " ";
    }

    
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(21);
    root->left->right = new node(12);

    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(7);
    root->right->left->left = new node(5);
    root->right->right->right = new node(8);
    root->right->left->left->left = new node(6);
    root->right->right->right->right = new node(9);

    Brute(root);
}