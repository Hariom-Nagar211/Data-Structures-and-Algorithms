#include<bits/stdc++.h>
using namespace std;

// 

void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>> grid)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int delRow=-1; delRow<=1; delRow++)
        {
            for(int delCol=-1; delCol<=1; delCol++)
            {
                int nrow = row + delRow;
                int ncol = col + delCol;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] == 1;
                    q.push({nrow, ncol});
                }    
            }
        }
    }
}

int cntIslands(vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for(int row=0; row<n; row++)
    {
        for(int col=0; col<m; col++)
        {
            if(grid[row][col] == 1 && vis[row][col] == 0)
            {
                bfs(row, col, vis, grid);
                cnt++;
            }
        }
        return cnt;
    }

    // TC : n*n + n*n*9
    // SC : n*n + n*n
}