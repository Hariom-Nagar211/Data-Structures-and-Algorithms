#include<bits/stdc++.h>
using namespace std;

// Que: Return index of any peak element in an array.
//      Peak element is defined as that element that is greater than both of its neighbors.
//      Assume 'arr[-1]' and 'arr[n]' as negative infinity.

int Optimal(vector<int> arr)
{
    int n = arr.size();

    if(n == 1) return 0;

    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    
    int low = 1;
    int high = n-2;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1])) return mid;
        else if(arr[mid] > arr[mid-1]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
    

    // Logic: Accept the array in which you find the element bigger than mid and proceed.
    // Beauty: Draw the curve and the mid can be peak, on dec, on inc side you will move towards mid
    //         by moving towards greater element.
    //    TC: log(2,n)

}

int main()
{
    vector<int> arr = {1,2,3,4,5,4,3,10,11,12,13};

    cout << Optimal(arr);
}