
// Large constraints — you’ll need a fast Prim’s/Kruskal’s.
// Link : https://www.spoj.com/problems/MST/

#include <bits/stdc++.h>
using namespace std;
 
int primMST(int V, const vector<vector<pair<int, int>>> &adj)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        vector<int> vis(V, 0);
 
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
 
int main() {
	// your code goes here
	int V, m;
	cin >> V >> m;
	
	vector<vector<pair<int, int>>> adj(V);
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		a--; b--;
		
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	cout << primMST(V, adj) << endl;
} 