#include<iostream>
#include<vector>
using namespace std;

// Que: Find the missing number in an array(1 to n, sorted)

void Logic()
{
    // Brute: Linear Search 
    //    TC: O(n^2), SC: O(1)

    // Better: Hashing
    //     TC: O(2n), SC: O(n)

    // Optimal_1: Sum all the numbers
    //        TC: O(2n), SC: O(1)

    // Optimal_2: XOR1(1-n) ---> XOR2(arr[i]) ---> XOR1 ^ XOR2
    //        TC: O(n), SC:O(1)
}

void Brute()
{
    int n = 5;
    int arr[4] = {1,2,3,4};

    for(int i=1; i<=n; i++)
    {
        int flag = 0;
        for(int j=0; j<n-1; j++)
        {
            if(i == arr[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout << "missing num is: " << i;
        }
    }
}

void Better()
{
    int n = 10;
    int arr[9] = {1,2,3,4,5,7,8,9,10};

    int hash[n+1] = {0};

    for(int i=1; i<n+1; i++)
    {
        if(arr[i-1] == i)
        {
            hash[i] = 1;
        }
        else
        {
            break;
        }
    }

    for(int i=1; i<n+1; i++)
    {
        if(hash[i] == 0)
        {
            cout << "missing num is: " << i;
            break;
        }
    }

}

void Optimal_1()
{
    int n = 10;
    int arr[n-1] = {1,2,3,4,5,7,8,9,10};

    int sum = 0;

    for(int i=0; i<n-1; i++)
    {
        sum = sum + arr[i];
    }

    int total_sum = n*(n+1)/2;

    cout << "Missing num is: " << total_sum-sum;
}

void Optimal_2()
{
    int n = 10;
    vector<int> arr(n-1);
    arr = {1,2,3,4,5,7,8,9,10};

    int XOR1 = 0;
    int XOR2 = 0;
    for(int i=0; i<n-1; i++)
    {
        XOR2 = XOR2^arr[i];
        XOR1 = XOR1^(i+1);
    }
    XOR1 = XOR1^n;

    cout << "Missing num is: " << (XOR1 ^ XOR2);
}

int main()
{
    // Brute();
    // Better();
    // Optimal_1();
    Optimal_2();

}