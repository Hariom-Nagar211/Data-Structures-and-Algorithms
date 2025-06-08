#include<bits/stdc++.h>
using namespace std;

// QUE : Maximum Points You Can Obtain from k Cards consucatively from front, back or both.

int f(vector<int> cards, int n, int k)
{
    int maxPoints = 0;
    for(int i=0; i<k; i++) maxPoints += cards[i];

    // k possible combinations, picking all points before i and after j
    int i = k-1; // k-1 cards left
    int j = n-2; // 1 card left
    int points = maxPoints;
    while(i >= 0)
    {
        points = points - cards[i] + cards[j+1];
        maxPoints = max(maxPoints, points);

        i--;
        j--;
    }

    return maxPoints;

    // LC : Trying all possible cases
    // TC : O(2k)
    // SC : 1
    
}

int main()
{
    vector<int> cards = {6,2,3,4,7,2,1,7,1};
    int n = cards.size();
    int k = 4;

    cout << f(cards, n, k) << endl;
}