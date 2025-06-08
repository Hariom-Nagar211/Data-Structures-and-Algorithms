#include<bits/stdc++.h>
using namespace std;

// QUE : Detect a cycle in directed graph using BFS

bool CourseSechedule(int V, vector<pair<int, int>> &prerequisites)
{
    vector<int> adj[V+1];
    for(auto it : prerequisites)
    {
        adj[it.first].push_back(it.second);
    }

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
    if(cnt == V) return true;
    else return false;
}

int main()
{
    int n = 5;

    vector<pair<int, int>> prerequisites;
    prerequisites = {{1,2},{4,3},{2,4},{4,1}};
    
    cout << CourseSechedule(n, prerequisites);
}