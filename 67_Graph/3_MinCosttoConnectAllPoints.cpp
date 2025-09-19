
// Prim’s Algorithm on a complete graph (requires understanding optimization).
// Link : https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
private:
    int primMST(int V, const vector<vector<pair<int, int>>> &adj)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        vector<int> vis(V, 0);

        vector<pair<int, int>> mst_edges;
        int total_cost = 0;

        pq.push({0, {0, -1}});
        while(!pq.empty())
        {
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            int wt = pq.top().first;
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
    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();
        vector<vector<pair<int, int>>> adj(V);
        for(int i=0; i<V-1; i++)
        {
            int pt1_x = points[i][0];
            int pt1_y = points[i][1];

            for(int j=i+1; j<V; j++)
            {
                int pt2_x = points[j][0];
                int pt2_y = points[j][1];

                int wt = abs(pt2_x - pt1_x) + abs(pt2_y - pt1_y);

                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        return primMST(V, adj);
        
    }
};