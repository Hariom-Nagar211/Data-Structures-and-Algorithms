
// Link : https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1

class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        
        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {-1, 1, 0, 0};
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        dis[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        
        while(!pq.empty())
        {
            int noder = pq.top().second.first;
            int nodec = pq.top().second.second;
            int node_dis_from_src = pq.top().first;
            pq.pop();
            
            for(int i=0; i<4; i++)
            {
                int newr = noder + dr[i];
                int newc = nodec + dc[i];
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m)
                {
                    int conn_node_row = newr;
                    int conn_node_col = newc;
                    int conn_node_dis_from_parent = grid[newr][newc];
                    
                    if(node_dis_from_src + conn_node_dis_from_parent < dis[newr][newc])
                    {
                        dis[newr][newc] = node_dis_from_src + conn_node_dis_from_parent;
                        pq.push({dis[newr][newc], {newr, newc}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
        
    }
};