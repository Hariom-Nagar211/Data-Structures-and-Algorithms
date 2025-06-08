#include<iostream> 
#include<vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid+1;
    vector<int> temp;
    
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

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int cnt = 0;

    while(i <= mid && j <= high)
    {
        if(arr[i] > 2*arr[j])
        {
            cnt += mid - i + 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if(low >= high) return cnt;

    int mid = (low+high)/2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return cnt;
}

void Optimal(vector<int> arr)
{
    int cnt = mergeSort(arr, 0 , arr.size()-1);
    cout << cnt;
}

int main()
{
    vector<int> arr = {40,25,19,12,9,6,2};

    Optimal(arr);
}