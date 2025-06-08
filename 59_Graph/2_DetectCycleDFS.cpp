#include<bits/stdc++.h>
using namespace std;

// QUE : Detect a cycle in a graph using DFS traversal.

bool DetectCycleHelper(int node, int parent, vector<int> adj[], int &vis[])
{
    // DFS traversal
    vis[node] = 1;
    for(auto adjecentNodes : adj[node])
    {
        if(vis[adjecentNodes] == 0)
        {
            if(DetectCycleHelper(adjecentNodes, node, adj, vis) == true) 
                return true;
        } 
        else if(adjecentNodes != parent) return true;
        return false;
    }
}

bool DetectCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    for(int i=0; i<v; i++)
    {
        if(!vis[i]) 
            if(DetectCycleHelper(i, -1, adj, vis) == true) return true;
    }
    return false;
}

int main()
{


    // TC : n + 2E
    // SC : n + n
    // Logic : Using previous node concept
}