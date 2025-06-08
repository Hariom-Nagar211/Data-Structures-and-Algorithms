#include<bits/stdc++.h>
using namespace std;

// Que: print all the unique set of combinations of 4 elements from array
// whose sum equals to target.

void Logic()
{
    /*
    Brute: 4 loops + set + temp(to sort)
       TC: n*n*n*n
       SC: C(n,4)

    Better: 3 loops + reverse sum approach
        TC: n*n*n
        SC: C(n,4)

    Optimal: 3 loops + sorting the array + 2 sum approach.
         TC: n*n*n
         SC: 1       
    */
}

void Brute(vector<int> arr)
{
    int n = arr.size();
    set<vector<int>> st;
    vector<vector<int>> ans;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                for(int l=k+1; l<n; l++)
                {
                    long long sum = arr[i];
                    sum += arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == 0)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    for(auto it : st)
    {
        ans.push_back(it);
    }
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void Better(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    set<vector<int>> st;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            set<long long> hashset;
            for(int k=j+1; k<n; k++)
            {
                long long sum = arr[i] + arr[j];
                sum += arr[k]; 
                int fourth = 0 - sum;
                if(hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    for(auto it : st)
    {
        ans.push_back(it);
    }
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void Optimal(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++)
    {
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1; j<n; j++)
        {
            if(j > i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l)
            {
                int sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum < 0)
                {
                    k++;
                }
                else if(sum > 0)
                {
                    l--;
                }
                else
                {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                    while(k < l && arr[k] == arr[k-1]) k++;
                    while(k < l && arr[l] == arr[l-1]) l--;
                }
            }
        }
    }
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    vector<int> arr = {1,-1,4,3,-4,7,0,-2,0,5,9,-6};

    Brute(arr);
    cout << endl;
    Better(arr);
    cout << endl;
    Optimal(arr);
}