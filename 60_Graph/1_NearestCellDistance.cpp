#include <bits/stdc++.h>
using namespace std;

// QUE : Find the distance of nearest cell contaning 1 in matrix contaning 0/1.

vector<vector<int>> NearestCellDistance(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> vis(n, vector<int>(m ,0));
    vector<vector<int>> dist(n , vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(matrix[i][j] == 1)
            {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            } 
        }
    }

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;

        for(int i=0; i<4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && vis[nrow][ncol] == 0)
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps+1});
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<int>> matrix = {{1, 0, 1},
                                  {1, 1, 0},
                                  {1, 0, 0}};

    vector<vector<int>> ans = NearestCellDistance(matrix);

    for(auto it : ans)
    {
        for(auto itt : it)
        {
            cout << itt << " ";
        }
        cout << endl;
    }


    // TC : n x m
    // SC : n x m
}