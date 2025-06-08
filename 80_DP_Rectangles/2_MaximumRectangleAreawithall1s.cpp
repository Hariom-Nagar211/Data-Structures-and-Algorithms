#include<bits/stdc++.h>
using namespace std;

// QUE : Largest Rectangle in Histogram

int Brute(vector<vector<int>> rec, int n, int m)
{
    vector<int> r(m, 0);
    int maxArea = INT_MIN;
    for(int row=0; row<n; row++)
    {
        for(int col=0; col<m; col++)
        {
            if(rec[row][col] == 1) r[col]++;
            else r[col] = 0;
        }
        for(int k=0; k<m; k++)
        {
            int i = k;
            int j = k;
            while(r[i-1] >= r[k] && i > 0) i--;
            while(r[j+1] >= r[k] && j < m-1) j++;
            int area = r[k]*(j-i+1);
            maxArea = max(area, maxArea);
        }
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> rectangles = {{1,0,1,0,0},
                                      {1,0,1,1,1},
                                      {1,1,1,1,1},
                                      {1,0,0,1,0}};
    int n = rectangles.size();
    int m = rectangles[0].size();

    cout << Brute(rectangles, n, m) << endl;
}