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

void preorder(node* root)
{
    vector<int> ans;
    if(root == NULL) return;

    stack<node*> st;
    st.push(root);
    while(!st.empty())
    {
        node* currentNode = st.top();
        ans.push_back(currentNode->data);
        st.pop();
        if(currentNode->right != NULL) st.push(currentNode->right);
        if(currentNode->left != NULL) st.push(currentNode->left);
    }

    for(auto it : ans)
    {
        cout << it << " ";
    }
}

void inorder(node* root)
{
    vector<int> ans;
    stack<node*> st;
    if(root == NULL) return;
    node* curr = root;

    while (curr != NULL || !st.empty()) 
    {
        // 1. Reach the leftmost node of curr
        while (curr != NULL) 
        {
            st.push(curr);
            curr = curr->left;
        }

        // 2. curr is now NULL (we've hit the leftmost)
        curr = st.top();
        st.pop();

        // 3. Visit the node
        cout << curr->data << " ";

        // 4. Move to the right subtree
        curr = curr->right;
    }
}

void postorder_2stacks(node* root)
{
    vector<int> ans;
    stack<node*> st1;
    stack<node*> st2;

    st1.push(root);
    while(!st1.empty())
    {
        node* currNode = st1.top();
        st1.pop();
        st2.push(currNode);
        if(currNode->left != NULL) st1.push(currNode->left);
        if(currNode->right != NULL) st1.push(currNode->right);
        
    }

    while(!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

}

void postorder_1stack(node* root)
{
    vector<int> ans;
    stack<node*> st1;

    st1.push(root);
    while(!st1.empty())
    {
        node* currNode = st1.top();
        st1.pop();
        ans.push_back(currNode->data);
        if(currNode->left != NULL) st1.push(currNode->left);
        if(currNode->right != NULL) st1.push(currNode->right);
        
    }

    for(int i=ans.size()-1; i>=0; i--)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder_2stacks(root);
    cout << endl;
    postorder_1stack(root);

}