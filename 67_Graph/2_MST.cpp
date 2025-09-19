
// Classic Prim’s implementation on adjacency list.
// Link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution {
  private:
  int primMST(int V, vector<vector<pair<int, int>>> &adj)
  {
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                    greater<pair<int, pair<int, int>>>> pq; // wt, cn, pn
        
      vector<int> vis(V, 0);
      
      vector<pair<int, int>> mst_edges;
      int total_cost = 0;
      
      pq.push({0, {0, -1}});
      while(!pq.empty())
      {
          int wt = pq.top().first;
          int node = pq.top().second.first;
          int parent = pq.top().second.second;
          pq.pop();
          
          if(vis[node]) continue;
          vis[node] = 1;
          
          if(parent != -1)
          {
              mst_edges.push_back({parent, node});
              total_cost += wt;
          }
          
          for(auto it : adj[node])
          {
              int conn_node = it.first;
              int edgeWt = it.second;
              
              if(!vis[conn_node])
              {
                  pq.push({edgeWt, {conn_node, node}});
              }
              
          }
      }
      return total_cost;
  }

  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        vector<vector<pair<int, int>>> graph(V);

        for (int i = 0; i < V; ++i) {
            for (auto it : adj[i]) {
                int neighbor = it[0];
                int weight = it[1];
                graph[i].push_back({neighbor, weight});
            }
        }

        return primMST(V, graph);
    }
};