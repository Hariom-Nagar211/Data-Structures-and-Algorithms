#include<bits/stdc++.h>
using namespace std;

int RottenOranges(vector<vector<int>> tray)
{
    int n = tray.size();
    int m = tray[0].size();
    vector<vector<int>> dummyTray = tray;
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(dummyTray[i][j] == 2) q.push({i, j});
        }
    }

    int time = 0;

    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int nrow[] = {-1, 0, +1, 0};
            int ncol[] = {0, +1, 0, -1};
            for(int i=0; i<4; i++)
            {
                int new_row = row + nrow[i];
                int new_col = col + ncol[i];
                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                    dummyTray[new_row][new_col] == 1)
                {
                    dummyTray[new_row][new_col] = 2;
                    q.push({new_row, new_col});
                }    

            }
        }
        time++;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(dummyTray[i][j] == 1) return -1;
        }
    }

    return time-1;

    // TC : n*m
    // SC : n*m + n*m
}

int main()
{
    vector<vector<int>> tray = {{2,1,1},
                                {1,1,0},
                                {0,1,1}};

    cout << RottenOranges(tray);

}