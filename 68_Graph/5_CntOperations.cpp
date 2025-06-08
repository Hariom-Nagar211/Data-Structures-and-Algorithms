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

// QUE : count the number minimum number of operations required to make
//       graph connected.

int CntOperations(int V, vector<vector<int>> &edges)
{
    DisjointSet ds(V);
    for(auto it : edges)
    {
        ds.UnionByRank(it[0],it[1]);
    }

    int E = edges.size();

    // special case
    if(E < V-1) return -1;

    // counting components
    int cnt = 0;
    for(int i=0; i<V; i++)
    {
        if(ds.FindUltPar(i) == i) cnt++;
    }

    // counting extra edges
    int extra_E = E - ((V-1)-(cnt-1));

    if(extra_E < cnt-1) return -1;

    //operations = components - 1
    return cnt-1;
}

int main()
{
    int V = 5;

    vector<vector<int>> adj;
    adj = {{0,1}, {0,2}, {1,2}, {3,4}};

    cout << CntOperations(V, adj);
}