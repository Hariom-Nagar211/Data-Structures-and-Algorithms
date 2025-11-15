#include<bits/stdc++.h>
using namespace std;

// Que : Pickup maximum fruits into the two baskets
// Link : https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();

        if(n <= 2) return n;

        pair<int, int> b1 = {-1, 0}; // fruit_type, fruit_count
        pair<int, int> b2 = {-1, 0};

        int i = 0;
        int j = 0;
        int maxCount = 0;
        while(j < n)
        {
            if(fruits[j] == b1.first) b1.second++;
            else if(fruits[j] == b2.first) b2.second++;
            else
            {
                if(b1.first == -1) b1 = {fruits[j], 1};
                else if(b2.first == -1) b2= {fruits[j], 1};
                else 
                {
                    while(b1.second != 0 && b2.second != 0)
                    {
                        if(fruits[i] == b1.first) b1.second--;
                        else b2.second--;

                        i++;
                    }

                    if(b1.second == 0)
                    {
                        b1.first = fruits[j];
                        b1.second++;
                    }
                    else
                    {
                        b2.first = fruits[j];
                        b2.second++;
                    }
                }
                
            }

            maxCount = max(maxCount, b1.second+b2.second);
            j++;
        }
        return maxCount;
        
        
    }
};
