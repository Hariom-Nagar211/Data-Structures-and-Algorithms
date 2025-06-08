#include <bits/stdc++.h>
using namespace std;

void FloodFillBFS(vector<vector<int>> &image, int row, 
                  int col, int colour)
{
    int n = image.size();
    int m = image[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    int prev_pixel = image[row][col];
    image[row][col] = colour;

    while (!q.empty())
    {
        int new_row = q.front().first;
        int new_col = q.front().second;
        q.pop();

        int row1 = new_row + 1;
        int col1 = new_col;
        if (row1 >= 0 && row1 < n && col1 >= 0 && col1 < m 
            && image[row1][col1] == prev_pixel)
        {
            image[row1][col1] = colour;
            q.push({row1, col1});
        }

        int row2 = new_row - 1;
        int col2 = new_col;
        if (row2 >= 0 && row2 < n && col2 >= 0 && col2 < m 
            && image[row2][col2] == prev_pixel)
        {
            image[row2][col2] = colour;
            q.push({row2, col2});
        }

        int row3 = new_row;
        int col3 = new_col + 1;
        if (row3 >= 0 && row3 < n && col3 >= 0 && col3 < m 
            && image[row3][col3] == prev_pixel)
        {
            image[row3][col3] = colour;
            q.push({row3, col3});
        }

        int row4 = new_row;
        int col4 = new_col - 1;
        if (row4 >= 0 && row4 < n && col4 >= 0 && col4 < m 
            && image[row4][col4] == prev_pixel)
        {
            image[row4][col4] = colour;
            q.push({row4, col4});
        }
    }
}

void dfs(vector<vector<int>> &image, int new_row, int new_col, 
        int colour, int prev_pixel)
{
    int n = image.size();
    int m = image[0].size();
    int row1 = new_row + 1;
    int col1 = new_col;
    if (row1 >= 0 && row1 < n && col1 >= 0 && col1 < m 
        && image[row1][col1] == prev_pixel)
    {
        image[row1][col1] = colour;
        dfs(image, row1, col1, colour, prev_pixel);
    }

    int row2 = new_row - 1;
    int col2 = new_col;
    if (row2 >= 0 && row2 < n && col2 >= 0 && col2 < m 
        && image[row2][col2] == prev_pixel)
    {
        image[row2][col2] = colour;
        dfs(image, row2, col2, colour, prev_pixel);
    }

    int row3 = new_row;
    int col3 = new_col + 1;
    if (row3 >= 0 && row3 < n && col3 >= 0 && col3 < m 
        && image[row3][col3] == prev_pixel)
    {
        image[row3][col3] = colour;
        dfs(image, row3, col3, colour, prev_pixel);
    }

    int row4 = new_row;
    int col4 = new_col - 1;
    if (row4 >= 0 && row4 < n && col4 >= 0 && col4 < m 
        && image[row4][col4] == prev_pixel)
    {
        image[row4][col4] = colour;
        dfs(image, row4, col4, colour, prev_pixel);
    }
}

void FloodFillDFS(vector<vector<int>> &image, int row, int col, int colour)
{
    int n = image.size();
    int m = image[0].size();
    int prev_pixel = image[row][col];
    image[row][col] = colour;

    dfs(image, row, col, colour, prev_pixel);
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1},
                                 {2, 2, 0},
                                 {2, 2, 2}};
    int row = 2;
    int col = 0;
    int colour = 3;
    // FloodFillBSF(image, row, col, colour);
    FloodFillDFS(image, row, col, colour);


    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            cout << image[i][j] << " ";
        }
    }
}
