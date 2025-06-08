#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Problem Statment:

// LC: Greedy + Algorithm
// TC: NlogN
// SC: 1

int miniPlatforms(vector<int> arr, vector<int> dep)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int cnt = 1;
    int maxCnt = 0;
    int i = 0;
    int j = 0;
    while(i < n)
    {
        if(arr[i] < dep[j]) {cnt++; i++;}
        else {cnt--; j++;}

        maxCnt = max(cnt, maxCnt);
    }
    return maxCnt;

}

int main()
{
    vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int> dep = {920, 1130, 1150, 1200, 1900, 2000};

    cout << miniPlatforms(arr, dep) << endl;
}