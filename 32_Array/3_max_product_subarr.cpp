#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// Que: Find the subarray with maximum product of elements from an array, print the product.

void Brute(vector<int> arr)
{
    int n = arr.size();
    int product;
    int max_product = 0;

    for(int i=0; i<n; i++)
    {
        product = 1;
        for(int j=i; j<n; j++)
        {
            product = product*arr[j];
            max_product = max(product,max_product);
        }
    }
    cout << max_product;

    // Logic: Cheaking for all subarrays product.
    //    TC: n*n
    //    SC: 1
}

void MyAproach(vector<int> arr)
{
    // not able to handle 0;

    int n = arr.size();
    int neg1 = 1;
    int index_neg1;
    int neg2 = 1;
    int index_neg2;
    int cnt_neg = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i] < 0)
        {
            cnt_neg++;
        }
    }
    if(cnt_neg%2 == 0)
    {
        int product = 1;
        for(int i=0; i<n; i++)
        {
            product = product*arr[i];
        }
        cout << product;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i] < 0)
        {
            neg1 = arr[i];
            index_neg1 = i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--)
    {
        if(arr[i] < 0)
        {
            neg2 = arr[i];
            index_neg2 = i;
            break;
        }
    }
    
    int prd1 = 1;
    int prd2 = 1;
    int prd3 = 1;
    int prd4 = 1;

    for(int i=0; i<n; i++)
    {
        if(i < index_neg1) prd1 = prd1*arr[i];
        if(i > index_neg1) prd2 = prd2*arr[i];
        if(i < index_neg2) prd3 = prd3*arr[i];
        if(i > index_neg2) prd4 = prd4*arr[i];
    }

    int max_prd1 = max(prd1, prd2);
    int max_prd2 = max(prd3, prd4);
    int max_prd = max(max_prd1, max_prd2);
    cout << max_prd;
}

void Optimal(vector<int> arr)
{
    int n = arr.size();
    int prefix = 1;
    int suffix = 1;
    int maxi = INT_MIN;

    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0) prefix = 1, i++;
        if(arr[n-i] == 0) suffix = 1, i++;
        
        prefix = prefix*arr[i];
        suffix = suffix*arr[n-i-1];

        maxi = max(maxi, max(prefix,suffix));
    }
    cout << maxi;

    // Logic: Observe that the ans is always a prefix or a suffix subarray around the negative.
    //    TC: n 
    //    SC: 1

}

int main()
{
    vector<int> arr = {2,3,-2,4,2};

    Brute(arr);
    cout << endl;
    MyAproach(arr);
    cout << endl;
    Optimal(arr);    
}