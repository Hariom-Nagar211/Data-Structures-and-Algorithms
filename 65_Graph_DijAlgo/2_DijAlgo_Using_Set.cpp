#include<bits/stdc++.h>
using namespace std;

// Dijkestra's Algorithm using set data structure.

vector<int> DijkAlgo(int V, vector<pair<int, int>> adj[])
{
    vector<int> dis(V, INT_MAX);
    dis[0] = 0;
    set<pair<int, int>> st;
    st.insert({0,0});

    while(!st.empty())
    {
        auto itt = *(st.begin());
        int node = itt.second;
        int node_dist_from_src = itt.first;
        st.erase(itt);

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int adjNode_dis_from_node = it.second;

            if(node_dist_from_src + adjNode_dis_from_node < dis[adjNode])
            {
                if(dis[adjNode] != INT_MAX) st.erase({dis[adjNode], adjNode});
                dis[adjNode] = node_dist_from_src + adjNode_dis_from_node;
                st.insert({dis[adjNode], adjNode});
            }
        }
        
    }
    return dis;

    // DS : vector<int> dis; set<pair<int, int>> st;
}

