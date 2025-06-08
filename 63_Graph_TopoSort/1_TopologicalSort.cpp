#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], stack<int> &st)
{
    vis[node] = 1;
    
    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> TopologicalSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;
    vector<int> ans;

    for(int i=0; i<V; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i, adj, vis, st);
        }
    }
    
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    int V = 6;

    vector<int> adj[V];
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0,1};
    adj[5] = {0,2};

    vector<int> ans = TopologicalSort(V, adj);
    for(int i=0; i<V; i++)
    {
        cout << ans[i] << " ";
    }
}