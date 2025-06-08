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

void Brute(node* root)
{
    stack<node*> st1;
    stack<node*> st2;
    vector<int> arr;

    st1.push(root);
    while(!st1.empty() || !st2.empty())
    {
        while(!st1.empty())
        {
            node* currNode1 = st1.top();
            st1.pop();
            arr.push_back(currNode1->data);
            if(currNode1->left != NULL)st2.push(currNode1->left);
            if(currNode1->right != NULL)st2.push(currNode1->right);

        }

        while(!st2.empty())
        {
            node* currNode2 = st2.top();
            st2.pop();
            arr.push_back(currNode2->data);
            if(currNode2->right != NULL)st1.push(currNode2->right);
            if(currNode2->left != NULL)st1.push(currNode2->left);
        }
    }
    
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    
}

void Optimal(node* root)
{
    queue<node*> q;
    vector<vector<int>> arr;
    bool flag = false;

    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for(int i=0; i<size; i++)
        {
            node* currNode = q.front();
            q.pop();
            temp.push_back(currNode->data);
            if(currNode->left != NULL)q.push(currNode->left);
            if(currNode->right != NULL)q.push(currNode->right);
        }
        if(flag) reverse(temp.begin(), temp.end());
        
        arr.push_back(temp);

        flag = !flag;
    }

    for(auto level : arr)
    {
        for(int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(7);
    root->right->left->left = new node(5);
    root->right->right->right = new node(8);
    root->right->left->left->left = new node(6);
    root->right->right->right->right = new node(9);

    Brute(root);
    cout << endl;
    Optimal(root);

}