#include<iostream>
#include<vector>
using namespace std;

void Brute(vector<int> arr)
{
    int n = arr.size();
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j]) cnt++;
        }
    }
    cout << cnt;
}

int merge(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
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
            cnt += (mid - left + 1);
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
        arr[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high)/2;
    
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);
    
    return cnt;

}

void Optimal(vector<int> arr)
{
    int n = arr.size();
    cout << mergeSort(arr, 0, arr.size()-1);

}

int main()
{
    vector<int> arr = {5,3,2,4,1}; // (5,3),(5,2),(5,4),(5,1),(3,2),(3,1),(2,1),(4,1)

    Brute(arr);
    cout << endl;
    Optimal(arr);
    
}