
// Link : https://leetcode.com/problems/path-with-maximum-probability/


class Solution {
private:
    double dijAlgo(int V, const vector<vector<pair<int, double>>> &adj, int start_node, int end_node)
    {
        vector<double> dis(V, 0);
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;

        dis[start_node] = 1;
        pq.push({1, start_node});

        while(!pq.empty())
        {
            int node = pq.top().second;
            double prob_node_from_src = pq.top().first;
            pq.pop();

            for(auto it : adj[node])
            {
                int conn_node = it.first;
                double prob_conn_node_from_parent = it.second;

                if(prob_node_from_src*prob_conn_node_from_parent > dis[conn_node])
                {
                    dis[conn_node] = prob_node_from_src*prob_conn_node_from_parent;
                    pq.push({dis[conn_node], conn_node});
                }
            }
        }
        return dis[end_node];

    }    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        int V = n;
        vector<vector<pair<int, double>>> adj(V);
        int e = edges.size();
        for(int i=0; i<e; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        double maxSuccProb = dijAlgo(V, adj, start_node, end_node);

        return maxSuccProb;
        
    }
};