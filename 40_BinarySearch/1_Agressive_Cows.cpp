#include<bits/stdc++.h>
using namespace std;

// Que: You are given array of poisitions where cows can stand, set the cows in such a way that 
//      the minimum distance between two cows is maximum.

int Brute(vector<int> arr, int cows)
{
    int n = arr.size();
    if(n < cows) return -1;
    sort(arr.begin(), arr.end());

    int dist = 1;
    int cnt_dist = 0;
    
    while(1)
    {
        int cnt_cows = 1;
        for(int i=0; i<n-1; i++)
        {
            cnt_dist += arr[i+1] - arr[i];
            if(cnt_dist >= dist)
            {
                cnt_dist = 0;
                cnt_cows++;
            }
            
            if(cnt_cows >= cows) break;
        }
        if(cnt_cows >= cows) dist++;
        else
        {
            return dist-1;
        }
    }
    return -1;
}

int Optimal(vector<int> arr, int cows)
{
    int n = arr.size();
    if(n < cows) return -1;
    sort(arr.begin(), arr.end());

    int cnt_dist = 0;
    int min_dist = 1;
    int max_dist = arr[n-1] - arr[0];

    int low = min_dist;
    int high = max_dist;
    while(low <= high)
    {
        int dist = (low + high)/2;
        
        int cnt_cows = 1;
        for(int i=0; i<n-1; i++)
        {
            cnt_dist += arr[i+1] - arr[i];
            if(cnt_dist >= dist)
            {
                cnt_dist = 0;
                cnt_cows++;
            }
            
            if(cnt_cows >= cows) break;
        }
        if(cnt_cows >= cows)
        {
            low = dist + 1;
        }
        else
        {
            high = dist - 1;
        }
    }
    return high;

}

int main()
{
    vector<int> arr = {0,4,3,7,9,10};
    int cows = 4;

    cout << Brute(arr, cows);
    cout << endl;
    cout << Optimal(arr, cows);
}
