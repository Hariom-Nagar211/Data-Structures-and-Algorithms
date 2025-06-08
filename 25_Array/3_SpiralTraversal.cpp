#include <iostream>
#include <vector>
using namespace std;

void f(vector<vector<int>> arr)
{
    int n = arr.size();
    vector<int> ans;
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = n - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(arr[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4, 5, 6},
                               {20, 21, 22, 23, 24, 7},
                               {19, 32, 33, 34, 25, 8},
                               {18, 31, 36, 35, 26, 9},
                               {17, 30, 29, 28, 27, 10},
                               {16, 15, 14, 13, 12, 11}};

    f(arr);
}
