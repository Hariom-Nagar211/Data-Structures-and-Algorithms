
// Link : https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Tip : Needs Dijkstra + limit on number of stops → use a modified version.

class Solution {
private:
    int dijAlgo(int V, vector<vector<pair<int, int>>> adj, int src, int dst, int k)
    {
        vector<int> dis(V, 1e9);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<int> cntStops(V, 1e9);

        dis[src] = 0;
        pq.push({0, src, 0});
        cntStops[src] = 0;
        
        while(!pq.empty())
        {
            auto [node_dis_from_src, node, stops] = pq.top();
            pq.pop();

            if(node == dst) return node_dis_from_src;

            if(stops > k) continue;

            for(auto it : adj[node])
            {
                int conn_node = it.first;
                int conn_node_dis_from_parent = it.second;

                if(node_dis_from_src + conn_node_dis_from_parent < dis[conn_node] || cntStops[conn_node] > stops+1)
                {
                    dis[conn_node] = node_dis_from_src + conn_node_dis_from_parent;
                    pq.push({dis[conn_node], conn_node, stops+1});
                    cntStops[conn_node] = stops + 1;
                }

            }
        }
        return -1;
    }    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        int V = n;
        vector<vector<pair<int, int>>> adj(V);

        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        return dijAlgo(V, adj, src, dst, k);
        
    }
};