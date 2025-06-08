#include<bits/stdc++.h>
using namespace std;

vector<int> TopoSortBFS(int V, vector<int> adj[])
{
    queue<int> q;
    int indegree[V] = {0};
    vector<int> ans;
    for(int i=0; i<V; i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for(int i=0; i<V; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
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

    vector<int> ans = TopoSortBFS(V, adj);
    for(int i=0; i<V; i++)
    {
        cout << ans[i] << " ";
    }
}