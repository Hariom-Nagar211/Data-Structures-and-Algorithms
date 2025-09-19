#include<bits/stdc++.h>
using namespace std;

// Shortest Path in Weighted undirected graph : Also Print Path Nodes.
// Link : https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1


class Solution {
  private:
  vector<int> dijAlgo(int V, vector<vector<pair<int, int>>> adj)
  {
      vector<int> dis(V+1, 1e9);
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      vector<int> parent(V+1);
      
      dis[1] = 0;
      pq.push({0, 1});
      parent[1] = -1;
      
      while(!pq.empty())
      {
          int node = pq.top().second;
          int dist_from_src = pq.top().first;
          pq.pop();
          
          for(auto it : adj[node])
          {
              int conn_node = it.first;
              int conn_node_dist_from_parent = it.second;
              
              if(dist_from_src + conn_node_dist_from_parent < dis[conn_node])
              {
                  dis[conn_node] = dist_from_src + conn_node_dist_from_parent;
                  pq.push({dis[conn_node], conn_node});
                  parent[conn_node] = node;
              }
              
          }
      }
      
      if(dis[V] == 1e9) return {-1};
      
      vector<int> path;
      path.push_back(dis[V]);
      path.push_back(V);
      int node = V;
      
      while(parent[node] != -1)
      {
          path.push_back(parent[node]);
          
          node = parent[node];
      }
      
      reverse(path.begin()+1, path.end());
      
      return path;
      
  }

  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        int V = n;
        vector<vector<pair<int, int>>> adj(V+1);
        
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        return dijAlgo(V, adj);
        
    }
};