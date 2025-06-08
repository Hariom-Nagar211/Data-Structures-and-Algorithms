#include<bits/stdc++.h>
using namespace std;

// Que : Find the number of ways to arrive at destination with shortest distance.

int CountPaths(int n, vector<vectoir<int>>& roads)
{
    // Making Adj list
    vector<pair<int, int>> adj[n];
    for(auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    // Dijkestra Algorithm
    vector<int> dist(n, INT_MAX);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1; // count the no of times destination is arrived from starting
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0});
    int mod = (int)(1e9+7);

    while(!pq.empty())
    {
        int city = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        for(auto it : adj[city])
        {
            int adjCity = it.first;
            int gap = it.second;
            if(distance + gap < dist[adjCity])
            {
                dist[adjCity] = distance + gap;
                pq.push({dist[adjCity], adjCity});
                ways[adjCity] = ways[city];
            }
            else if(distance + gap == dist[adjCity])
            {
                ways[adjCity] = (ways[city] + ways[adjCity])%mod;
            }
            
        }
    }
    return ways[n-1]%mod;
    
}