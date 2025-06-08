#include <bits/stdc++.h>
using namespace std;

// QUE : Count number of islands

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int FindUltPar(int node)
    {
        if (parent[node] == node)
            return node;
        // Path Compression
        return parent[node] = FindUltPar(parent[node]);
    }
    void UnionByRank(int u, int v)
    {
        int ulp_u = FindUltPar(u);
        int ulp_v = FindUltPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
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

vector<int> cntIslands(int n, int m, vector<vector<int>> &operators)
{
    
}
