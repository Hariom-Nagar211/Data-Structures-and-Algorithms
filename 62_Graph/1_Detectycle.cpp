#include <bits/stdc++.h>
using namespace std;

bool Helper_DetectCycle(int node, vector<int> adj[], int vis[], int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
        if(!vis[it])
        {
            if(Helper_DetectCycle(it, adj, vis, pathVis) == true) 
                return true;
        }
        else if(pathVis[it]) return true;
    }
    pathVis[node] = 0;
    return false;
}

bool DetectCycle(int V, vector<int> adj[])
{
    int vis[V + 1] = {0};
    int pathVis[V + 1] = {0};
    for (int i = 1; i < V + 1; i++)
    {
        if (vis[i] == 0)
        {
            if (Helper_DetectCycle(i, adj, vis, pathVis) == true)
                return true;
        }
    }
    return false;
}

int main()
{
    int V = 10;

    vector<int> adj[V + 1];
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4, 7};
    adj[4] = {5};
    adj[5] = {6};
    adj[7] = {5};
    adj[8] = {2, 9};
    adj[9] = {10};
    adj[10] = {8};

    cout << DetectCycle(V, adj);
}