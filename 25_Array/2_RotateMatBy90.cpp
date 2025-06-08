#include<iostream>
using namespace std;

// Que: Rotate a matrix by 90 degree.

// Brute
// LC: Use Hash Array
// TC: N*N
// SC: N*N

// Optimal
// LC: Transpose then reverse each row.
// TC: N*N
// SC: 1

void Brute(int arr[4][4], int n, int m)
{
    int temp[n][m] = {0};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            temp[i][j] = arr[j][i];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            arr[i][j] = temp[i][m-j-1];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

void Optimal(int arr[4][4], int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<m; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<(m/2); j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][m-j-1];
            arr[i][m-j-1] = temp;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 4;
    int m = 4;
    int arr[4][4] = {{1, 2, 3, 4},   // 13,9,5,1
                     {5, 6, 7, 8},   // 14,10,6,2
                     {9, 10,11,12},  // 15,11,7,3
                     {13,14,15,16}}; // 16,12,8,4

    // Brute(arr, n, m);
    Optimal(arr, n, m);

}