#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int check[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            if(dfs(it, adj, vis, pathVis, check) == true) return true;
        }
        if(vis[it] == 1 && pathVis[it] == 1) return true;
    }
    check[node] = 1;
    pathVis[node] = 0;
    return false;

}

vector<int> SafeNodes(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};
    vector<int> ans;
    for(int i=0; i<V; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i, adj, vis, pathVis, check);
        }
    }
    
    for(int i=0; i<V; i++)
    {
        if(check[i] == 1)
        {
            ans.push_back(i);
        }
    }
    return ans;

}

int main()
{
    int V = 12;

    vector<int> adj[V];
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4,5};
    adj[4] = {6};
    adj[5] = {6};
    adj[6] = {7};
    adj[8] = {9,1};
    adj[9] = {10};
    adj[10] = {8};
    adj[11] = {9};

    vector<int> ans = SafeNodes(V, adj);

    for(auto it : ans)
    {
        cout << it << " ";
    }
}
