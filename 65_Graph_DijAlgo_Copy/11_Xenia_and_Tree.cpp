#include<bits/stdc++.h>
using namespace std;

// Link : https://codeforces.com/problemset/problem/342/E
// Concept : Incremental Multi-Source BFS
 
const int RED = 1, BLUE = 0;
typedef long long ll;

vector<vector<int>> adj;  
vector<int> color;
vector<int> dis;
 
void dijAlgo(ll V, int src) 
{
  queue<int> q;
  q.push(src);
 
  color[src] = RED;
  dis[src] = 0;
 
  while (!q.empty()) 
  {
    int node = q.front();
    q.pop();

    for (auto conn_node : adj[node]) 
    {
        if(dis[node] + 1 < dis[conn_node]) 
        {
            dis[conn_node] = dis[node] + 1;
            q.push({conn_node});
        }
      
    }
  }
}
 
int main() 
{
    ll V, m;
    cin >> V >> m;
    
    adj.resize(V);
    color.assign(V, BLUE);
    dis.assign(V, 1e9);


    for (int i = 0; i < V-1; ++i) 
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dijAlgo(V, 0);

    for (int i = 0; i < m; ++i) 
    {
        int qn, src;
        cin >> qn >> src;
        src--;
        if (qn == 1) 
        {
            dijAlgo(V, src);
        } 
        else 
        {
            cout << dis[src] << "\n";
        }
    }

    return 0;
}
