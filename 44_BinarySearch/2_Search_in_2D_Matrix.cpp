#include<bits/stdc++.h>
using namespace std;

// Que: Search the given target in sorted 2d matrix if it is present return true else false.

bool Optimal1(vector<vector<int>> matrix, int target)
{
    int n = matrix.size(); // rows
    int m = matrix[0].size(); // columns

    int low1 = 0;
    int high1 = n-1;
    while(low1 <= high1)
    {
        int mid1 = (low1 + high1)/2;
        if(matrix[mid1][0] <= target  && target <= matrix[mid1][m-1])
        {
            int low2 = 0;
            int high2 = m-1;
            while(low2 <= high2)
            {
                int mid2 = (low2 + high2)/2;
                if(matrix[mid1][mid2] == target) return true;
                else if(matrix[mid1][mid2] < target) low2 = mid2 + 1;
                else high2 = mid2 - 1;
            }
            return false;
        }
        else if(matrix[mid1][m-1] < target) low1 = mid1 + 1;
        else high1 = mid1 - 1;
    }

    // TC: logn * logm

}

bool Optimal2(vector<vector<int>> matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n*m - 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int row = mid/m;
        int col = mid%m;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;

    // TC: log(n*m)
}

int main()
{
    vector<vector<int>> matrix = {{3 ,4 ,7 ,9},
                                  {12,13,16,18},
                                  {20,21,23,29}};
    int target = 7;

    cout << Optimal1(matrix, target) << endl;
    cout << Optimal2(matrix, target);                                
}