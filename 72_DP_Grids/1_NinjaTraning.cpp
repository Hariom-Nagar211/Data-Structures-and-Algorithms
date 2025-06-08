#include<bits/stdc++.h>
using namespace std;

// QUE : https://bit.ly/3F4yl8z

// Recursion
int f(int day, int last, vector<vector<int>> Mat) // last -> prev day task
{
    int maxi = 0;
    if(day == Mat.size()-1)
    {
        for(int i=0; i<3; i++)
        {
            if(i != last)
            {
                maxi = max(Mat[Mat.size()-1][i], maxi);
            }
        }
        return maxi;
    }

    maxi = 0;
    for(int i=0; i<3; i++)
    {
        if(i != last)
        {
            int points = Mat[day][i] + f(day+1, i, Mat);
            maxi = max(points, maxi);
        }
    }
    return maxi;

}

// Recursion + DP(Memoization)
int f2(int day, int last, vector<vector<int>> Mat, vector<vector<int>> dp)
{
    int maxi = 0;
    if(day == Mat.size()-1)
    {
        for(int i=0; i<3; i++)
        {
            if(i != last)
            {
                maxi = max(Mat[Mat.size()-1][i], maxi);
            }
        }
        return dp[day][last] = maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    maxi = 0;
    for(int i=0; i<3; i++)
    {
        if(i != last)
        {
            int points = Mat[day][i] + f(day+1, i, Mat);
            maxi = max(points, maxi);
        }
    }
    return dp[day][last] = maxi;

    // TC : N X 4 X 3
    // SC : N + (N X 4)
}

// Recursion + DP(Tabulation)
int f3(int n, vector<vector<int>> Mat)
{
    int m = Mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0)); 

    dp[0][0] = Mat[0][0];
    dp[0][1] = Mat[0][1];                       
    dp[0][2] = Mat[0][2];                         

    for(int day = 1; day < n; day++)
    {
        for(int last = 0; last < 3; last++)
        {
            for(int task=0; task<3; task++)
            {
                if(task != last)
                {
                    int points = Mat[day][task] + dp[day-1][last];
                    dp[day][task] = max(dp[day][task], points);
                }
            }
        }
    }                        
    return max(dp[n-1][1], max(dp[n-1][2], dp[n-1][0]));

    // TC : N x 4 x 3
    // SC : N x 4
}

// Recursion + DP(Tabulation) with Space Optimization
int f4(int n, vector<vector<int>> Mat)
{
    vector<int> prev(4, 0); 

    prev[0] = max(Mat[0][1], Mat[0][2]);
    prev[1] = max(Mat[0][0], Mat[0][2]);                         
    prev[2] = max(Mat[0][1], Mat[0][3]);                         
    prev[3] = max(Mat[0][1], max(Mat[0][2], Mat[0][1])); 

    for(int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for(int last = 0; last < 4; last++)
        {
            temp[last] = 0;

            for(int task=0; task<3; task++)
            {
                if(task != last)
                {
                    temp[last] = max(temp[last], Mat[day][last] + prev[task]);
                }
            }
        }
        prev = temp;
    }                        
    return prev[3];

    // TC : N x 4 x 3
    // SC : 1
}

int main()
{
    vector<vector<int>> Mat = {{ 10 , 20 , 30 },
                               { 30 , 20 , 10 },
                               { 100, 15 , 5  }};

    int n = Mat.size();                     

    cout << f(2,3, Mat) << endl;

    vector<vector<int>> dp(n, vector<int>(4, -1)); // day x last (how many distinct value they can take)
    cout << f2(2,3, Mat, dp) << endl;
    
    cout << f3(3, Mat) << endl;
    
    cout << f4(3, Mat);   

}