#include<bits/stdc++.h>
using namespace std;

pair<int, int> Optimal(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int el = -1;
    int row_el = -1;

    int low = 0;
    int high = m-1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        for(int i=0; i<n; i++)
        {
            int temp = el;
            el = max(el, matrix[i][mid]);
            if(temp < el) row_el = i;
        }
        if(mid == 0)
        {
            if(el > matrix[row_el][mid+1]) return {row_el, mid};
            else low = mid + 1;
        }
        else if(mid == m-1)
        {
            if(el > matrix[row_el][mid-1]) return {row_el, mid};
            else high = mid - 1;
        }
        else
        {
            if((el > matrix[row_el][mid+1]) && (el > matrix[row_el][mid-1])) return {row_el, mid};
            else if(matrix[row_el][mid-1] > el) high = mid - 1;
            else low = mid + 1;
        }
    }

    // TC: n*log(2, m)
}

int main()
{
    vector<vector<int>> matrix = {{4,2,5,1,4,5},
                                  {2,9,3,2,3,2},
                                  {1,7,6,0,1,3},
                                  {3,6,2,3,7,2}};

    cout << Optimal(matrix).first << " " << Optimal(matrix).second;                              
}