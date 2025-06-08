#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;
public :
    DisjointSet(int n)
    {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    int FindUltPar(int node)
    {
        if(parent[node] == node) return node;
        // Path Compression
        return parent[node] = FindUltPar(parent[node]);  
    }
    void UnionBySize(int u, int v)
    {
        int ulp_u = FindUltPar(u);
        int ulp_v = FindUltPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if(size[ulp_v] < size[ulp_u])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } 
    }
};

int main()
{
    DisjointSet ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    if(ds.FindUltPar(3) == ds.FindUltPar(7)) cout << "Same" << endl;
    else cout << "Not Same" << endl;

    ds.UnionBySize(3,7);
    if(ds.FindUltPar(3) == ds.FindUltPar(7)) cout << "Same" << endl;
    else cout << "Not Same" << endl;

}