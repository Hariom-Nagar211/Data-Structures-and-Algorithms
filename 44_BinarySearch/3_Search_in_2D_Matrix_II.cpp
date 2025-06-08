#include<bits/stdc++.h>
using namespace std;

// Que: Return the coordinates of given element in a 2D matrix whose 
//      individual rows and columns are sorted.

pair<int, int> Optimal1(vector<vector<int>> matrix, int target)
{
    int n = matrix.size(); // row
    int m = matrix[0].size(); // col

    int low1 = 0;
    int high1 = n-1;
    while(low1 <= high1)
    {
        int mid1 = (low1 + high1)/2;
        if(matrix[mid1][mid1] == target) return {mid1, mid1};
        else if(matrix[mid1][mid1] < target) low1 = mid1;
        else if(matrix[mid1][mid1] > target) high1 = mid1 - 1;
        if(low1 == mid1 && high1 == mid1) break;
    }

    int low2 = low1;
    int high2 = m-1;
    while(low2 <= high2)
    {
        int mid2 = (low2 + high2)/2;
        if(matrix[low1][mid2] == target) return {low1, mid2};
        else if(matrix[low1][mid2] < target) low2 = mid2 + 1;
        else high2 = mid2 - 1;
    }

    int low3 = low1;
    int high3 = n-1;
    while(low3 <= high3)
    {
        int mid3 = (low3 + high3)/2;
        if(matrix[mid3][low1] == target) return {mid3, low1};
        else if(matrix[mid3][low1] < target) low3 = mid3 + 1;
        else high3 = mid3 - 1;
    }
    return {-1,-1};

    // Logic: Digonal
    //    TC: log(2, n) + log(2 , m-low1+1) + log(2, n-low1+1)
}

pair<int, int> Optimal2(vector<vector<int>> matrix, int target)
{
    int n = matrix.size(); // row
    int m = matrix[0].size(); // col

    int row = 0;
    int col = m-1;
    while(row < n && col >= 0)
    {
        if(matrix[row][col] == target) return {row, col};
        else if(matrix[row][col] < target) row++;
        else col--;
    }
    return {-1, -1};
    
    // TC: n+m;
}

int main()
{
    vector<vector<int>> matrix = {{ 1  , 4  , 7  , 11 , 15 },
                                  { 2  , 5  , 8  , 12 , 19 },
                                  { 3  , 6  , 9  , 16 , 22 },
                                  { 10 , 13 , 14 , 17 , 24 },
                                  { 18 , 21 , 23 , 26 , 30 }};
    int target = 14;

    cout << Optimal1(matrix, target).first << " " << Optimal1(matrix, target).second; 
    cout << endl;
    cout << Optimal2(matrix, target).first << " " << Optimal2(matrix, target).second;                                

}