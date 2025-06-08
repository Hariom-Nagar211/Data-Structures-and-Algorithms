#include<bits/stdc++.h>
using namespace std;

// Que: Return the index of row with maximum number of 1s(if two return the minimum).

int Brute(vector<vector<int>> arr)
{
    int n = arr.size(); // rows
    int m = arr[0].size(); // columns

    int max_sum = 0;
    int ans = 0;

    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=0; j<m; j++)
        {
            sum += arr[i][j];
        }
        if(max_sum < sum) ans = i;
        max_sum = max(max_sum, sum);
    }
    return ans;
}

int Optima(vector<vector<int>> arr)
{
    int n = arr.size(); // rows
    int m = arr[0].size(); // columns

    int ans = 0;
    int ones = 0;
    int tempOnes = 0;

    for(int i=0; i<n; i++)
    {
        int low = 0;
        int high = m-1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[i][mid] == 1)
            {
                ones = m - mid;
                high = mid - 1;
            }
            else low = mid + 1;
            
            if(tempOnes < ones) ans = i;
            tempOnes = max(ones, tempOnes);
        }
    }
    return ans;

    // TC: n*log(2, n)
    // Note : you can use lower or upper bound concept directly.

}

int main()
{
    vector<vector<int>> matrix = {{0,0,1,1,1},
                                  {0,0,0,0,0},
                                  {0,1,1,1,1},
                                  {0,0,0,0,0},
                                  {0,1,1,1,1}};

    cout << Brute(matrix); 
    cout << endl;
    cout << optimal(matrix);                             


}