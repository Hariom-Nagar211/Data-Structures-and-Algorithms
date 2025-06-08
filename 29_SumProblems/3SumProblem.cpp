#include<bits/stdc++.h> 
using namespace std;

// Que: print all the unique triplets from an array whose sum equals to 0.

void Logic()
{
    /*
    Brute: Cheaq for all possible triplets if find sort it then store it in set.
       TC: n*n*n
       SC: n

    Optimal: Sort the array and use two pointer approach.
         TC: nlogn + n*n
         SC: 1
    */
}

void Brute(vector<int> arr)
{
    vector<vector<int>> ans;
    set<vector<int>> st;
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    for(auto it: st)
    {
        ans.push_back(it);
    }
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void Optimal(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size(); i++)
    {
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0)
            {
                j++;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k-1]) k--;                
            }
        }
        
    }
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    vector<int> arr = {-1,0,1,4,3,-2,5,6,0,3};// -2,-1,0,0,1,3,3,4,5,6

    Brute(arr);
    cout << endl;
    Optimal(arr);

}