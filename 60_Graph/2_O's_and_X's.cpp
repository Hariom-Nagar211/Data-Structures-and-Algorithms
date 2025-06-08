#include <bits/stdc++.h>
using namespace std;

// QUE : Convert all O's into X's if surrounded by X's from all four sides.

vector<vector<char>> Convert_X_into_O(vector<vector<char>> mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<char>> ans(n, vector<char>(m, 'x'));
    queue<pair<int, int>> q;

    int trav = 0;
    while (trav < m)
    {
        if(mat[0][trav] == 'o')
        {
            ans[0][trav] = 'o';
            q.push({0, trav});

        } 
        trav++;
    }

    trav = 0;
    while(trav < n)
    {
        if(mat[trav][m-1] == 'o')
        {
            ans[trav][m-1] = 'o';
            q.push({trav, m-1});

        }
        trav++;
    }

    trav = m-1;
    while(trav >= 0)
    {
        if(mat[n-1][trav] == 'o')
        {
            ans[n-1][trav] = 'o';
            q.push({n-1, trav});

        }
        trav--;
    }

    trav = n-1;
    while(trav >= 0)
    {
        if(mat[0][trav] == 'o')
        {
            ans[0][trav] = 'o';
            q.push({0, trav});

        }
        trav--;
    }

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

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
                && mat[nrow][ncol] == 'o' && ans[nrow][ncol] == 'x')
            {
                ans[nrow][ncol] = 'o';
                q.push({nrow, ncol});
            }
        }
    }
    return ans; 
}

int main()
{
    vector<vector<char>> mat = {{'x', 'x', 'x', 'x'},
                                {'x', 'o', 'x', 'x'},
                                {'x', 'o', 'o', 'x'},
                                {'x', 'o', 'x', 'x'},
                                {'x', 'x', 'o', 'o'}};

    vector<vector<char>> ans = Convert_X_into_O(mat);

    for(auto row : ans)
    {
        for(auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}