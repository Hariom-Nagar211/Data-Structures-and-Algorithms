#include<bits/stdc++.h>
using namespace std;

// Problem Statment:

// LC: Greedy Algorithm
// TC: N
// SC: 1

bool sellLemonade(vector<int> LemonadeChange)
{
    int n = LemonadeChange.size();

    int 5rsCoins = 0;
    int 10rsCoins = 0;
    int 20rsCoins = 0;

    for(int i=0; i<n; i++)
    {
        if(LemonadeChange[i] == 5) 5rsCoins++;
        else if(LemonadeChange[i] == 10)
        {
            if(5rsCoins)
            {
                5rsCoins--;
                10rsCoins++;
            }
            else return false;
        }
        else
        {
            if(5rsCoins && 10rsCoins)
            {
                5rsCoins--;
                10rsCoins--;
                20rsCoins++;
            }
            else if(5rsCoins >= 3)
            {
                5rsCoins -= 3;
                20rsCoins++;
            }
            else return false;
        }
    }
    return true;
}