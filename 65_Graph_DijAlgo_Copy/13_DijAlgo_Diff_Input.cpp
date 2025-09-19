#include<bits/stdc++.h>
using namespace std;

// Link : https://www.spoj.com/problems/SHPATH/
// Note : Multiple test cases, cities with string names → more input parsing needed.

int dijAlgo(int V, vector<vector<pair<int, int>>> &adj, int src, int dst) 
{
    vector<long long> dis(V, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dis[src] = 0;
    pq.push({0, src});
  
    while(!pq.empty()) 
    {
        int node = pq.top().second;
        long long node_dis_from_src = pq.top().first;
        pq.pop();

        if(dis[node] < node_dis_from_src) continue;

        for(auto it : adj[node])
        {
            int conn_node = it.first;
            int conn_node_dis_from_parent = it.second;

            if(node_dis_from_src + conn_node_dis_from_parent < dis[conn_node])
            {
                dis[conn_node] = node_dis_from_src + conn_node_dis_from_parent;
                pq.push({dis[conn_node], conn_node});
            }
        }
    }
    return dis[dst];
}
 
int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int V;
        cin >> V;

        unordered_map<string, int> mpp; // city_name, city_index
        vector<vector<pair<int, int>>> adj(V);
        for(int i=0; i<V; i++)
        {
            string city;
            cin >> city;

            mpp[city] = i;

            int nbr;
            cin >> nbr;

            for(int j=0; j<nbr; j++)
            {
                int a, b;
                cin >> a >> b;
                a--;

                adj[i].push_back({a,b});
                adj[a].push_back({i,b});
            }
        }

        int np;
        cin >> np;
        for(int i=0; i<np; i++)
        {
            string a, b;
            cin >> a >> b;

            int src = mpp[a];
            int dst = mpp[b];

            cout << dijAlgo(V, adj, src, dst) << endl;
        }
        cout << endl;

    }

}
