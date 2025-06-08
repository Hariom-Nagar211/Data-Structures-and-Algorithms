#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array where each element represents the maximum number of steps 
// you can jump forward from that element, return true if we can reach the last index starting 
// from the first index. Otherwise, return false.

// LC: We traverse the array once from the end to the beginning.
// TC: O(n) 
// SC: O(1)

bool JumpGame(vector<int> jumpSize)
{
    int n = jumpSize.size();

    bool tracker = true;
    int zeroJumpIndex = -1;
    for(int i=n-1; i>=0; i--)
    {
        if(jumpSize[i] == 0)
        {
            tracker = false;
            zeroJumpIndex = i;
            while(tracker == false && i >= 0)
            {
                if(jumpSize[i] > (zeroJumpIndex - i)) tracker = true;
                i--;
            }
            if(tracker == false) return false;
        }
    }
    return true;
}

int main()
{
    vector<int> jumpSize = {2,3,1,0,4};
    
    cout << JumpGame(jumpSize);
}