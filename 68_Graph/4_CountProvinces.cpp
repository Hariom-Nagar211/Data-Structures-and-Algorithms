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

int cntProvinces(int V, vector<vector<int>> adj)
{
    DisjointSet ds(V);
    ds.UnionByRank(0,1);
    ds.UnionByRank(1,2);
    ds.UnionByRank(3,4);

    int cnt = 0;
    for(int i=0; i<V; i++)
    {
        if(ds.FindUltPar(i) == i) cnt++;
    }
    return cnt;
}

int main()
{
    int V = 5;

    vector<vector<int>> adj;
    adj = {{0,1}, {1,2}, {3,4}};

    cout << cntProvinces(V, adj);
}