#include<bits/stdc++.h>
using namespace std;

// QUE : 

int f(int i, int j1, int j2, vector<vector<int>> grid, int r, int c)
{
    if(i >= r || j1 < 0 || j1 >= c
             || j2 < 0 || j2 >= c) return -1e9;
    if(i == r-1 && j1 != j2) return grid[i][j1] + grid[i][j2];
    if(i == r-1 && j1 == j2) return grid[i][j1];

    if(j1 != j2)
    {
        int c1 = grid[i][j1] + grid[i][j2] + f(i+1, j1-1, j2-1, grid, r, c);
        int c2 = grid[i][j1] + grid[i][j2] + f(i+1, j1-1, j2, grid, r, c);
        int c3 = grid[i][j1] + grid[i][j2] + f(i+1, j1-1, j2+1, grid, r, c);
        int c4 = grid[i][j1] + grid[i][j2] + f(i+1, j1, j2-1, grid, r, c);
        int c5 = grid[i][j1] + grid[i][j2] + f(i+1, j1, j2, grid, r, c);
        int c6 = grid[i][j1] + grid[i][j2] + f(i+1, j1, j2+1, grid, r, c);
        int c7 = grid[i][j1] + grid[i][j2] + f(i+1, j1+1, j2-1, grid, r, c);
        int c8 = grid[i][j1] + grid[i][j2] + f(i+1, j1+1, j2, grid, r, c);
        int c9 = grid[i][j1] + grid[i][j2] + f(i+1, j1+1, j2+1, grid, r, c);

        return max({c1, c2, c3, c4, c5, c6, c7, c8, c9});
    }
    else
    {
        int c1 = grid[i][j1] + f(i+1, j1-1, j2-1, grid, r, c);
        int c2 = grid[i][j1] + f(i+1, j1-1, j2, grid, r, c);
        int c3 = grid[i][j1] + f(i+1, j1-1, j2+1, grid, r, c);
        int c4 = grid[i][j1] + f(i+1, j1, j2-1, grid, r, c);
        int c5 = grid[i][j1] + f(i+1, j1, j2, grid, r, c);
        int c6 = grid[i][j1] + f(i+1, j1, j2+1, grid, r, c);
        int c7 = grid[i][j1] + f(i+1, j1+1, j2-1, grid, r, c);
        int c8 = grid[i][j1] + f(i+1, j1+1, j2, grid, r, c);
        int c9 = grid[i][j1] + f(i+1, j1+1, j2+1, grid, r, c);

        return max({c1, c2, c3, c4, c5, c6, c7, c8, c9});
    }
}

// Recurson + DP(Memoization)
int f2(int i, int j1, int j2, vector<vector<int>> grid, int r, int c,
    vector<vector<vector<int>>> &dp)
{
    if(i >= r || j1 < 0 || j1 >= c
        || j2 < 0 || j2 >= c) return -1e9;
    if(i == r-1 && j1 != j2) return grid[i][j1] + grid[i][j2];
    if(i == r-1 && j1 == j2) return grid[i][j1];

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2]; 

    int A[] = {-1, 0, 1};
    int B[] = {-1, 0, 1};

    int maxi = INT_MIN;
    if(j1 != j2)
    {
        for(int p : A)
        {
            for(int q : B)
            {
                int val = grid[i][j1] + grid[i][j2] 
                        + f2(i+1, j1+p, j2+q, grid, r, c, dp);
                maxi = max(val, maxi);
            }
        }
        return maxi;
    }
    else
    {
        for(int p : A)
        {
            for(int q : B)
            {
                int val = grid[i][j1] 
                        + f2(i+1, j1+p, j2+q, grid, r, c, dp);
                maxi = max(val, maxi);
            }
        }
        return maxi;
    }

    // if(j1 != j2)
    // {
    //     int c1 = grid[i][j1] + grid[i][j2] + f2(i+1, j1-1, j2-1, grid, r, c, dp);
    //     int c2 = grid[i][j1] + grid[i][j2] + f2(i+1, j1-1, j2, grid, r, c, dp);
    //     int c3 = grid[i][j1] + grid[i][j2] + f2(i+1, j1-1, j2+1, grid, r, c, dp);
    //     int c4 = grid[i][j1] + grid[i][j2] + f2(i+1, j1, j2-1, grid, r, c, dp);
    //     int c5 = grid[i][j1] + grid[i][j2] + f2(i+1, j1, j2, grid, r, c, dp);
    //     int c6 = grid[i][j1] + grid[i][j2] + f2(i+1, j1, j2+1, grid, r, c, dp);
    //     int c7 = grid[i][j1] + grid[i][j2] + f2(i+1, j1+1, j2-1, grid, r, c, dp);
    //     int c8 = grid[i][j1] + grid[i][j2] + f2(i+1, j1+1, j2, grid, r, c, dp);
    //     int c9 = grid[i][j1] + grid[i][j2] + f2(i+1, j1+1, j2+1, grid, r, c, dp);

    //     return dp[i][j1][j2] = max({c1, c2, c3, c4, c5, c6, c7, c8, c9});
    // }
    // else
    // {
    //     int c1 = grid[i][j1] + f2(i+1, j1-1, j2-1, grid, r, c, dp);
    //     int c2 = grid[i][j1] + f2(i+1, j1-1, j2, grid, r, c, dp);
    //     int c3 = grid[i][j1] + f2(i+1, j1-1, j2+1, grid, r, c, dp);
    //     int c4 = grid[i][j1] + f2(i+1, j1, j2-1, grid, r, c, dp);
    //     int c5 = grid[i][j1] + f2(i+1, j1, j2, grid, r, c, dp);
    //     int c6 = grid[i][j1] + f2(i+1, j1, j2+1, grid, r, c, dp);
    //     int c7 = grid[i][j1] + f2(i+1, j1+1, j2-1, grid, r, c, dp);
    //     int c8 = grid[i][j1] + f2(i+1, j1+1, j2, grid, r, c, dp);
    //     int c9 = grid[i][j1] + f2(i+1, j1+1, j2+1, grid, r, c, dp);

    //     return dp[i][j1][j2] = max({c1, c2, c3, c4, c5, c6, c7, c8, c9});
    // }
}        

// DP(Tabulation)
int f3(vector<vector<int>> grid, int r, int c)
{
    
}

int main()
{
    vector<vector<int>> grid = {{2 , 3 , 1 , 2},
                                  {3 , 4 , 2 , 2},
                                  {5 , 6 , 3 , 5}};

    int r = grid.size();
    int c = grid[0].size();

    cout << f(0, 0, c-1, grid, r, c) << endl;

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c , vector<int>(c, -1)));
    cout << f2(0, 0, c-1, grid, r, c, dp) << endl;
}