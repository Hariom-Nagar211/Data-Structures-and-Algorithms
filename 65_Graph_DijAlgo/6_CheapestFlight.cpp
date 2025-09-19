#include<bits/stdc++.h>
using namespace std;

int CheapestFlight(int n, vector<vector<int>>& flights, int src, int dest, int k)
{
    vector<int> dist(n, 1e9);
    queue<pair<int, pair<int, int>>> q;
    dist[src] = 0;
    q.push({-1, {0,src}});

    int size = flights.size();

    while(!q.empty())
    {
        int node = q.front().second.second;
        int dis = q.front().second.first;
        int steps = q.front().first;
        q.pop();
        
        if(steps + 1 > k) continue;
        for(int it=0; it<size; it++)
        {
            if(flights[it][0] == node)
            {
                int adjNode = flights[it][1];
                int edge = flights[it][2];

                if(dis + edge < dist[adjNode] && steps + 1 <= k)
                {
                    dist[adjNode] = dis + edge;
                    q.push({steps+1, {dist[adjNode], adjNode}});
                }
            }
        }
    }
    if(dist[dest] == 1e9) return -1;
    return dist[dest];
} 