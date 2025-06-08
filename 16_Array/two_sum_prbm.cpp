#include<bits/stdc++.h>
using namespace std;

// Que: Find the index of elements whose sum is equal to target.

// Brute
// LC : Try All Possible Combinations
// TC : N*N
// SC : 1

// Better
// LC : Use Map
// TC : O(nlogn) , O(n)[unordered map]
// SC : N

// Optimal
// LC : Sorting + Two Pointers
// TC : N*logN
// SC : 1

void better(vector<int> arr, int t)
{
    int n = arr.size();

    map<int, int> mpp;
    for(int i=0; i<n; i++)
    {
        mpp[arr[i]] = i;
    }

    for(int i=0; i<n; i++)
    {
        int e = arr[i];
        if(mpp.find(t-e) != mpp.end())
        {
            cout << "YES, indexes are: " << mpp[e] << " " << mpp[t-e];
            return;
        }
    }
    cout << "NOOO!";
    return;
}

void merg(vector <int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;  
    }

    for (int i = low; i <= high; i++) 
    {
        arr[i] = temp[i - low];
    }

}

void mergSort(vector<int> &arr, int low, int high)
{
    if(low >= high) return;
    int mid = (low + high)/2;
    mergSort(arr, low, mid);
    mergSort(arr, mid+1, high);
    merg(arr, low, mid, high);

}

void optimal(vector<int> arr, int t)
{
    int n = arr.size();
    mergSort(arr, 0, n-1);

    int begin = 0;
    int end = n-1;

    while(begin < end)
    {
        int sum = arr[begin] + arr[end];
        if(sum > t)
        {
            end--;
        }
        else if(sum < t)
        {
            begin++;
        }
        else if(sum == t)
        {
            cout << "YES" <<endl;
            return;
        }
    }
    cout << "NOOO!";
    

}

int main()
{
    //better({2,6,5,8,11}, 16);

    optimal({2,6,5,8,11}, 10);
}