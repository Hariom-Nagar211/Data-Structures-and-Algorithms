#include<bits/stdc++.h>
using namespace std;

// Que: Find the length of longest consucative Sequence.

void Logic()
{
    /*
    Brute: Select + Linear Search + Counter.
       TC: O(n*n)
       SC: O(1);

    Optimal_1: Sort, len, maxLen.
           TC: O(nlogn) + O(n)
           SC: O(1);

    Optimal_2: Use unordered set
           TC: [O(1)(best and avg case) or O(n)(wrost or rare case)]
                + [O(n) + O(2n) or O(n)*O(n)(rare case)]
           SC: O(n)             
    */
}

void Optimal_1(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int len = 1;
    int maxLen = 1;

    for(int i=0; i<arr.size()-1; i++)
    {
        if(arr[i+1] == arr[i]) continue;

        if(arr[i+1] == arr[i] + 1)
        {
            len = len + 1;
            maxLen = max(maxLen, len);
        }
        else
        {
            len = 1;
        }
    }

    cout << maxLen;
    
}

void Optimal_2(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> st;
    int longest = 1;

    for(int i=0; i<n; i++)
    {
        st.insert(arr[i]);
    }

    for(auto it: st)
    {
        if(st.find(it-1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }

    cout << endl << longest;
}

int main()
{
    vector<int> arr = {100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    Optimal_1(arr);
    Optimal_2(arr);
}