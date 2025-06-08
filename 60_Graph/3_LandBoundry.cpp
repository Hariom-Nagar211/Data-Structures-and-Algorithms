#include<bits/stdc++.h>
using namespace std;

int ClosedLands(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int cnt_total_ones = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 1) cnt_total_ones++;
        }
    }

    int cnt_open_ones = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int it = 0;
    while(it <= m-1)
    {
        if(grid[0][it] == 1)
        {
            q.push({0, it});
            vis[0][it] = 1;
            cnt_open_ones++;
        } 
        it++;
    }

    it = 1;
    while(it <= n-1)
    {
        if(grid[it][m-1] == 1) 
        {
            q.push({it, m-1});
            vis[it][m-1] = 1;
            cnt_open_ones++;
        }
        it++;
    }
    
    it = m-2;
    while(it >= 0)
    {
        if(grid[n-1][it] == 1) 
        {
            q.push({n-1, it});
            vis[n-1][it] = 1;
            cnt_open_ones++;
        }
        it--;
    }
    it = n-2;
    while(it > 0)
    {
        if(grid[it][0] == 1)
        {
            q.push({it, 0});
            vis[it][0] = 1;
            cnt_open_ones++;
        }
        it--;
    }

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1}; 

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
                cnt_open_ones++;
            }
        }
    }
    return (cnt_total_ones - cnt_open_ones);
}

int main()
{
    vector<vector<int>> grid = {{0,0,0,1},
                                {0,1,1,0},
                                {0,1,1,0},
                                {0,0,0,1},
                                {0,1,1,0}};

    cout << ClosedLands(grid);                            
}