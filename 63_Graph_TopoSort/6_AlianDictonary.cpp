#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], stack<int> &st, int vis[])
{
    vis[node] = 1;
    
    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            dfs(it, adj, st, vis);
        }
    }
    st.push(node);
}

vector<int> TopoSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;
    vector<int> ans;

    for(int i=0; i<V; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i, adj, st, vis);
        }
    }

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

string AlianDictonary(int n, int k, string dict[])
{
    vector<int> adj[k];
    for(int i=0; i<n-1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(), s2.size());

        for(int ptr=0; ptr<len; ptr++)
        {
            if(s1[ptr] != s2[ptr]) 
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topo = TopoSort(k, adj);
    string ans = "";
    for(auto it : topo)
    {
        ans = ans + char(it + 'a');
    }
    return ans;

    
}

int main()
{
    int n = 5;
    int k = 4;
    string dict[n] = {"baa", "abcd", "abca", "cab", "cad"};

    string ans = AlianDictonary(n, k, dict);
    for(auto it : ans)
    {
        cout << it << " ";
    }
}