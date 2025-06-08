#include<bits/stdc++.h>
using namespace std;

// QUE : Find ways with maze and dead cells

// Recursion
int f(int i, int j, vector<vector<int>> maze, int n, int m)
{
    if(i == n-1 && j == m-1) return 1;
    if(i > n-1 || j > m-1) return 0;
    if(maze[i][j] == -1) return 0;

    int right = f(i, j+1, n, m);
    int down = f(i+1, j, n, m);

    return right + down;
    
}

int main()
{
    int n = 3;
    int m = 3;
    vector<vector<int>> maze = {{0 , 0 , -1},
                                {0 , 0 , -1},
                                {0 , 0 ,  0}};

    cout << f(n-1, m-1, maze) << endl;  

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << f2(n-1, m-1, maze, dp) << endl;

    cout << f3(n, m, maze);
}