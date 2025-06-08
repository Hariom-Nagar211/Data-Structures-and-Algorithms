#include<bits/stdc++.h>
using namespace std;

// Que: 

void merge(vector<int> &arr, int low, int mid, int high)
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

    for(int i=low; i<=high; i++)
    {
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high) return;

    int mid = (low + high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

bool is_possible(vector<int> arr, int days, int cap)
{
    int n = arr.size();
    int load = 0;
    int cnt_days = 1;

    for(int i=0; i<n; i++)
    {
        if(load + arr[i] > cap)
        {
            cnt_days++;
            load = arr[i];
        }
        else load += arr[i];
    }
    return cnt_days <= days;
}

int Brute(vector<int> arr, int days)
{
    int n = arr.size();
    mergeSort(arr, 0, n-1);

    int mini = arr[n-1];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    int maxi = sum;

    for(int i=mini; i<=maxi; i++)
    {
        if(is_possible(arr,days,i) == 1)
        {
            return i;
        }
    }
    return -1;

    // TC: nlogn + n + (mini-maxi+1)*n
}

int Optimal(vector<int> arr, int days)
{
    int n = arr.size();
    mergeSort(arr, 0, n-1);

    int mini = arr[n-1];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    int maxi = sum;

    int ans = -1;
    int low = mini;
    int high = maxi;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(is_possible(arr, days, mid) == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;

    // TC: nlogn + n + log(2,mini-maxi+1)*n
}

int main()
{
    vector<int> arr = {2,4,8,8,9,12,13};
    int days = 5;

    cout << Brute(arr, days);
    cout << endl;
    cout << Optimal(arr, days);
}