#include<bits/stdc++.h>
using namespace std;

int ShortestDistance(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> destination)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, pair<int, int>>> q;
    dist[src.first][src.second] = 0;
    q.push({0, {src.first,src.second}});

    if(src == destination) return 0;

    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    while(!q.empty())
    {
        int dis = q.front().first;
        int node_row = q.front().second.first;
        int node_col = q.front().second.second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int node_adjRow = node_row + delRow[i];
            int node_adjCol = node_col + delCol[i];
            if(node_adjRow >= 0 && node_adjRow < n && node_adjCol >= 0 && node_adjCol < m)
            {
                if(grid[node_adjRow][node_adjCol] == 1)
                {
                    if(dist[node_adjRow][node_adjCol] > dist[node_row][node_col] + 1)
                    {
                        dist[node_adjRow][node_adjCol] = dist[node_row][node_col] + 1;
                        q.push({dist[node_row][node_col] + 1, {node_adjRow, node_adjCol}});
                        if(node_adjRow == destination.first && node_adjCol == destination.second)
                        {
                            return dist[node_adjRow][node_adjCol];
                        }
                    }
                }
            }
        }
    }
    return -1;

}

int main()
{

}