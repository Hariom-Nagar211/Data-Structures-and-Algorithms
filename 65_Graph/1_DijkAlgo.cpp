#include<bits/stdc++.h>
using namespace std;

// Dijkestra's Algorithm using priorith Queue

vector<int> DijAlgo(int V, vector<pair<int, int>> adj[])
{
    vector<int> dis(V, INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq; // {distance, node}
    dis[0] = 0;
    pq.push({0,0});

    while(!pq.empty())
    {
        int node = pq.top().second;
        int node_dis_from_src = pq.top().first;
        pq.pop();

        for(auto it : adj[node])
        {
            int conn_node = it.first;
            int conn_node_dis_from_parent = it.second;

            if(conn_node_dis_from_parent + node_dis_from_src < dis[conn_node])
            {
                dis[conn_node] = conn_node_dis_from_parent + node_dis_from_src;
                pq.push({dis[conn_node],conn_node});
            }
        }
    }
    return dis;

    // TC : ElogV 
}

int main()
{
    int V = 6;
    vector<pair<int, int>> adj[V];
    adj[0] = {{1,4},{2,4}};
    adj[1] = {{0,4},{2,2}};
    adj[2] = {{0,4},{1,2},{3,3},{4,1},{5,6}};
    adj[3] = {{2,3},{5,2}};
    adj[4] = {{2,1},{5,3}};
    adj[5] = {{3,2},{4,3},{2,6}};

    vector<int> ans = DijAlgo(V, adj);
    for(auto it : ans)
    {
        cout << it << " ";
    }
}