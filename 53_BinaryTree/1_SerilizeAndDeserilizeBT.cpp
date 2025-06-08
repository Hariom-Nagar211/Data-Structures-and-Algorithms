#include <bits/stdc++.h>
using namespace std;

// QUE : Write two functions Serilize and Deserilize(you are given root of BT)
// Serilize : root ---> string
// Deserilise : string ---> root

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<string> Serialize(node *root)
{
    queue<node *> q;
    vector<string> s;
    q.push(root);

    while (!q.empty())
    {
        node *currNode = q.front();
        q.pop();

        if (currNode == NULL)
        {
            s.push_back("#");
            s.push_back(",");
        }
        else
        {
            s.push_back(to_string(currNode->data));
            s.push_back(",");
        }

        if (currNode != NULL)
        {
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return s;

    // Logic : Using Level Order Traversal
}

node* Deserialize(vector<string> s) 
{
    if (s.empty() || s[0] == "#") return nullptr;

    node* root = new node(stoi(s[0]));
    queue<node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < s.size()) 
    {
        node* currNode = q.front();
        q.pop();

        // Process left child
        if (s[i] != "#") 
        {
            currNode->left = new node(stoi(s[i]));
            q.push(currNode->left);
        }
        i++;

        // Process right child
        if (i < s.size() && s[i] != "#") 
        {
            currNode->right = new node(stoi(s[i]));
            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(13);
    root->right->left = new node(4);
    root->right->right = new node(5);

    vector<string> s = Serialize(root);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
}