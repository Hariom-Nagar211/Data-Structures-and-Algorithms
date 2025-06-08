#include<bits/stdc++.h>
using namespace std;

bool Helper_isBipertiteBFS(int V, vector<int> adj[], int start, int vis[])
{
    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(auto adjecentNode : adj[node])
        {
            if(vis[adjecentNode] == -1)
            {
                vis[adjecentNode] = (!vis[node]);
                q.push(adjecentNode);
            }

            if(vis[adjecentNode] == vis[node]) return false;
        }
    }
    return true;
}

bool Helper_isBipertiteDFS(int V, vector<int> adj[], int node, int vis[])
{
    for(auto adjecentNode : adj[node])
    {
        if(vis[adjecentNode] == -1)
        {
            vis[adjecentNode] = (!vis[node]);
            if(Helper_isBipertiteDFS(V, adj, adjecentNode, vis) == false) return false;
        }

        if(vis[adjecentNode] == vis[node]) return false;
    }  
    return true;  
}

bool isBipertite(int V, vector<int> adj[])
{
    int vis[V+1];
    for(int i=0; i<V+1; i++) vis[i] = -1;

    for(int i=1; i<V+1; i++)
    {
        if(vis[i] == -1) 
        {
            vis[i] = 0;
            if(Helper_isBipertiteBFS(V, adj, i, vis) == false) return false;
            // if(Helper_isBipertiteDFS(V, adj, i, vis) == false) return false;

        } 
    }
    return true;
}



int main()
{
    int V = 6;

    vector<int> adj[V+1];
    adj[1] = {2};
    adj[2] = {3,5};
    adj[3] = {2,4};
    adj[4] = {3,5,6};
    adj[5] = {2,4};
    adj[6] = {4};

    cout << isBipertite(V, adj);
}