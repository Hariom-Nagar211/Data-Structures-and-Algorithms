#include<bits/stdc++.h>
using namespace std;

vector<int> SafeNodes(int V, vector<int> adj[])
{
    vector<int> newAdj[V];
    for(int i=0; i<V; i++)
    {
        for(auto it : adj[i])
        {
            newAdj[it].push_back(i);
        }
    }

    int indegree[V] = {0};
    for(int i=0; i<V; i++)
    {
        for(auto it : newAdj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<V; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for(auto it : newAdj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
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