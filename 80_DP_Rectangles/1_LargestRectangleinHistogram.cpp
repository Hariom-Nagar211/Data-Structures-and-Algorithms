#include<bits/stdc++.h>
using namespace std;

// QUE : Largest Rectangle in Histogram

int Brute(vector<int> r, int n)
{
    int maxArea = INT_MIN;
    for(int k=0; k<n; k++)
    {
        int i = k;
        int j = k;
        while(r[i-1] >= r[k] && i > 0) i--;
        while(r[j+1] >= r[k] && j < n-1) j++;
        int area = r[k]*(j-i+1);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int main()
{
    vector<int> rectangles = {2,1,5,6,2,3,1};
    int n = rectangles.size();

    cout << Brute(rectangles, n) << endl;
}