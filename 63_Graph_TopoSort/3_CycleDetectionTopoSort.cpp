#include<bits/stdc++.h>
using namespace std;

// QUE : Detect a cycle in directed graph using BFS

bool CycleDetectionBFS(int V, vector<int> adj[])
{
    queue<int> q;
    int indegree[V+1] = {0};
    indegree[0] = -1;
    for(int i=1 ;i<V+1; i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for(int i=1; i<V+1; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    int cnt = 0;
    while(!q.empty())
    {
        int node = q.front();
        cnt++;
        q.pop();

        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(cnt == V) return false;
    else return true;
}

int main()
{
    int V = 5;

    vector<int> adj[V+1];
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4,5};
    adj[4] = {2};
    
    cout << CycleDetectionBFS(V, adj);
}