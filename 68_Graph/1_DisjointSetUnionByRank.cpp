#include<bits/stdc++.h>
using namespace std;

// 🔍 Problem without rank:
// When we do union operations (i.e., merge two sets), we build a tree structure.
// If we blindly attach one set to another without any logic, the tree might become very deep. 
// Then FindUltPar() (which traverses up the tree to find the root) will become slow.
// We want to keep the tree as flat as possible, so that both find and union become efficient.

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

    void UnionByRank(int u, int v) // TC : 4*alpha - constant
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

int main()
{
    DisjointSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);
    if(ds.FindUltPar(3) == ds.FindUltPar(7)) cout << "Same" << endl;
    else cout << "Not Same" << endl;

    ds.UnionByRank(3,7);
    if(ds.FindUltPar(3) == ds.FindUltPar(7)) cout << "Same" << endl;
    else cout << "Not Same" << endl;

}