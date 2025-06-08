#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void leftShift(std::vector<int>& arr, int k) 
{
    int n = arr.size();
    k = k % n;
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());

    // LC : Reversal Algorithm
    // TC : N
    // SC : 1
}

void rightShift(std::vector<int>& arr, int k) 
{
    int n = arr.size();
    k = k % n;
    reverse(arr.end() - k, arr.end());
    reverse(arr.begin(), arr.end() - k);
    reverse(arr.begin(), arr.end());

    // LC : Reversal Algorithm
    // TC : N
    // SC : 1
}
