#include<bits/stdc++.h>
using namespace std;

// QUE : Find the no of unique icelands in an matrix.

int CountUniqueIcelands(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int, int>>> st;
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 1 && vis[i][j] == 0)
            {
                // Traversal
                vector<pair<int, int>> iceland;
                q.push({i,j});
                vis[i][j] = 1;
                iceland.push_back({0,0});

                int delRow[] = {-1, 0, +1, 0};
                int delCol[] = {0, +1, 0, -1};

                int startRow = i;
                int startCol = j;

                while(!q.empty())
                {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();

                    for(int i=0; i<4; i++)
                    {
                        int nrow = row + delRow[i];
                        int ncol = col + delCol[i];
                        
                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                            && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                        {
                            iceland.push_back({nrow-startRow, ncol-startCol});
                            q.push({nrow, ncol});
                            vis[nrow][ncol] = 1;
                        }
                    }
                }
                st.insert(iceland);
            }
        }
    }
    return st.size();
}

int main()
{
    vector<vector<int>> grid  = {{1,1,0,1,1},
                                 {1,0,0,0,0},
                                 {0,0,0,1,1},
                                 {1,1,0,1,0}};

    cout << CountUniqueIcelands(grid);                             
}