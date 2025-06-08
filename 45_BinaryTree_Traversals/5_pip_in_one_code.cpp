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

void pip(node* root)
{
    if(root == NULL) return;

    stack<pair<node*, int>> st;
    vector<int> preorder, inorder, postorder;

    st.push({root, 1});
    node* currentNode = st.top().first;
    int state = st.top().second;
    while(!st.empty()) 
    {
        if(st.top().second == 1) 
        {
            preorder.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->left != NULL) 
            {
                st.push({st.top().first->left, 1});
            }
        } else if(st.top().second == 2) 
        {
            inorder.push_back(st.top().first->data);
            st.top().second++;
            if(sright != NULL) 
            {
                st.push({st.top().first->right, 1});
            }t.top().first->
        } else if(st.top().second == 3) 
        {
            postorder.push_back(st.top().first->data);
            st.pop();
        }
    }

    // Print the traversals
    cout << "Preorder: ";
    for(int data : preorder) {
        cout << data << " ";
    }
    cout << "\nInorder: ";
    for(int data : inorder) {
        cout << data << " ";
    }
    cout << "\nPostorder: ";
    for(int data : postorder) {
        cout << data << " ";
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

    pip(root);
}