#include<bits/stdc++.h>
using namespace std;

// Que: 

int Brute(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            arr.push_back(matrix[i][j]);
        }
    }

    sort(arr.begin(), arr.end());
    int med = n*m/2;
    return arr[med];

    // TC: n*m + n*mlog(n*m);
    // SC: n+m;
}

int ub(vector<int> arr, int x)
{
    int n = arr.size();
    int ans = n;

    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;

}

int smallerEqual(vector<vector<int>> matrix, int x)
{
    int cnt = 0;
    for(int i=0; i<matrix.size(); i++)
    {
        cnt += ub(matrix[i], x);
    }
    return cnt;
}

int Optimal(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 1;
    int high = n*m;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int num = smallerEqual(matrix, mid); 
        if(num <= (m*n/2)) low = mid + 1;
        else high = mid - 1;
    }
    return low;

    // TC: log(2, pow(10,9))*n*log(2, m)
    // SC: 1
}

int main()
{
    vector<vector<int>> matrix = {{ 1 , 5  , 7  , 9  , 11 },
                                  { 2 , 3  , 4  , 5  , 10 },
                                  { 9 , 10 , 12 , 14 , 16 }};

    cout << Brute(matrix);
    cout << endl;
    cout << Optimal(matrix);
}