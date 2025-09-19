#include<bits/stdc++.h>
using namespace std;

// Network Delay Time : Classic problem where you use Dijkstra to find the time it takes for a 
//                      signal to reach all nodes.
// Link : https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it : times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dis(n+1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dis[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            int node = pq.top().second;
            int node_dis_from_src = pq.top().first;
            pq.pop();

            for(auto it : adj[node])
            {
                int conn_node = it.first;
                int conn_node_dis_fron_parent = it.second;

                if(node_dis_from_src + conn_node_dis_fron_parent < dis[conn_node])
                {
                    dis[conn_node] = node_dis_from_src + conn_node_dis_fron_parent;
                    pq.push({dis[conn_node], conn_node});
                }
            }
        }

        int maxi = -1;
        for(int i=1; i<=n; i++)
        {
            maxi = max(dis[i], maxi);

            if(dis[i] == 1e9) return -1;
        }
        return maxi;
        
    }
};