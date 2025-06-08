#include<iostream>
#include<vector>
using namespace std;

// Que: Set the corresponding rows and columns to zeros if it contatin zero.

void Logic()
{
    /*
    Brute: Iterate and set 1 to -1 ---> Iterate and set -1 to 0.
       TC: O[(n*m)*(n+m) + (n*m)]
       SC: O(1)

    Better: Two arrays row and col keep track.
        TC: O(2n*m) 
        SC: O(m+n)  

    */
}


void matRow(vector<vector<int>> &mat, int i, int n)
{
    for(int j=0; j<n; j++)
    {
        if(mat[i][j] != 0)
        {
            mat[i][j] = -1;
        }
    }
}

void matCol(vector<vector<int>> &mat, int j, int m)
{
    for(int i=0; i<m; i++)
    {
        if(mat[i][j] != 0)
        {
            mat[i][j] = -1;
        }
    }
}

void Brute(vector<vector<int>> mat, int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] == 0)
            {
                matRow(mat, i ,n);
                matCol(mat, j, m);
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] == -1)
            {
                mat[i][j] = 0;
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void Better(vector<vector<int>> mat, int m, int n)
{
    int row[m] = {0};
    int col[n] = {0};

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(row[i] == 1 || col[j] == 1)
            {
                mat[i][j] = 0;
            } 
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

}

void Optimal(vector<vector<int>> mat, int m, int n)
{
    int col = 1;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] == 0)
            {
                mat[i][0] = 0;
                if(j != 0)
                {
                    mat[0][j] = 0;
                }
                else
                {
                    col = 0;
                }
                
            }
        }
    }

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(mat[i][0] == 0 || mat[0][j] == 0)
            {
                mat[i][j] = 0;
            }
        }
    }

    if(mat[0][0] == 0)
    {
        for(int j=0; j<n; j++) mat[0][j] = 0;
    }
    if(col == 0)
    {
        for(int i=0; i<m; i++) mat[i][0] = 0;
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    int m = 4;
    int n = 4;
    vector<vector<int>> mat = {{1,1,1,1},
                               {1,0,0,1},
                               {1,1,0,1},
                               {1,0,1,1}};
    
    // Brute(mat, m, n);
    // Better(mat, m, n);
    Optimal(mat, m, n);

}