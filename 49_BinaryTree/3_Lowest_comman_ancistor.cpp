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

bool path1(node* root, vector<int> &arr1, int t1)
{
    if(!root) return false;

    arr1.push_back(root->data);
    if(root->data == t1) return true;

    if(path1(root->left, arr1, t1) 
    || path1(root->right, arr1, t1)) return true;

    arr1.pop_back();
    return false;
}

bool path2(node* root, vector<int> &arr2, int t2)
{
    if(!root) return false;

    arr2.push_back(root->data);
    if(root->data == t2) return true;

    if(path2(root->left, arr2, t2) 
    || path2(root->right, arr2, t2)) return true;

    arr2.pop_back();
    return false;
}

int LowestCommanAnsistor(node* root, int t1, int t2)
{
    vector<int> arr1;
    vector<int> arr2;
    path1(root, arr1, t1);
    path2(root, arr2, t2);

    int LCA = -1;
    for(int i=0; i<arr1.size(); i++)
    {
        if(arr1[i] != arr2[i])
        {
            LCA = arr1[i-1];
            break;
        } 
    }
    return LCA;
}

node* LCA(node* root, node* p, node* q)
{
    if(root == NULL || root == p || root == q) return root;

    node* left = LCA(root->left, p, q);
    node* right = LCA(root->right, p, q);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
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

    int t1 = 4, t2 = 5;
    cout << LowestCommanAnsistor(root, t1, t2) << endl;
    cout << LCA(root, root->left->left, root->left->right)->data;


}