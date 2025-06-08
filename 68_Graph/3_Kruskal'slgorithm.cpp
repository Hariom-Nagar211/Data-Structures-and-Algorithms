#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;
public :
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    int FindUltPar(int node)
    {
        if(parent[node] == node) return node;
        // Path Compression
        return parent[node] = FindUltPar(parent[node]);  
    }
    void UnionByRank(int u, int v)
    {
        int ulp_u = FindUltPar(u);
        int ulp_v = FindUltPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        } 
    }
};

void KruskalAlgo(int V, vector<vector<int>> adj[])
{
    DisjointSet ds(V);

    // Making updated adj list
    vector<pair<int, pair<int, int>>> edges;
    for(int i=0; i<V; i++)
    {
        for(auto it : adj[i])
        {
            int node = i;
            int adjNode = it[0];
            int wt = it[1];

            edges.push_back({wt, {node, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());

    // Appling Kruskal Algorithm
    int sum = 0;
    vector<pair<int, int>> MST;
    for(auto it : edges)
    {
        int wt = it.first;
        int node = it.second.first;
        int adjNode = it.second.second;

        if(ds.FindUltPar(node) != ds.FindUltPar(adjNode))
        {
            ds.UnionByRank(node, adjNode);
            MST.push_back({node, adjNode});
            sum += wt;
        }

    }

    // Printing MST
    for(auto it : MST)
    {
        cout << it.first << "---" << it.second << endl;
    }
    cout << "Sum is : " << sum << endl;
}

int main()
{
    int V = 5;

    vector<vector<int>> adj[V];
    adj[0] = {{1,2},{2,1}};
    adj[1] = {{0,2},{2,1}};
    adj[2] = {{0,1},{1,1},{4,2},{3,2}};
    adj[3] = {{2,2},{4,1}};
    adj[4] = {{2,2},{3,1}};

    KruskalAlgo(V, adj);
}