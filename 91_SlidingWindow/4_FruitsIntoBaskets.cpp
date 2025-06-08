#include<bits/stdc++.h>
using namespace std;

// Que : Pickup maximum fruits into the two baskets

int f(vector<int> trees, int n)
{
    int i = 0;
    int j = 1;
    int maxFruits = 0;
    int varity = 1;

    while(j < n)
    {
        if(trees[j] != trees[j-1]) varity++;

        while(varity > 2)
        {
            if(trees[i] != trees[i+1]) varity--;
            i++;
        }

        maxFruits = max(maxFruits, j-i+1);

        j++;
    }

    cout << maxFruits << endl;
}

int main()
{
    vector<int> trees = {3,3,3,1,2,1,1,2,3,3,4};
    int n = trees.size();

    f(trees, n);
}
