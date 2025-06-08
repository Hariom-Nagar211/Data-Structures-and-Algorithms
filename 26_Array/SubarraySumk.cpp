#include<bits/stdc++.h>
using namespace std;

// Que: Count the number of subarrays with sum k.

void Logic()
{
   /*
   Brute: Generate all the subarrays, Find sum, Cheaque for k.
      TC: O(n*n*n)
      SC: O(1)

   Better: Generate all the subarrays and find sum inside generating loop,
       TC: O(n*n)
       SC: O(1)

   Optimal: preSum, Map, cnt.
        TC: O(n);
        SC: O(n); 

        Note: for unordered_map, best and avg TC:O(1) but wrost O(n);
              for simple map, wrost TC:(logn)       
   */
}

void Better(vector<int> arr, int k)
{
   int cnt = 0;

   for(int i=0; i<arr.size(); i++)
   {
      int sum = 0;
      for(int j=i; j<arr.size(); j++)
      {
         sum += arr[j];
         if(sum == k)
         {
            cnt++;
         }
      }
   }
   cout << cnt << endl;
}

void Optimal(vector<int> arr, int k)
{
   unordered_map<int,int> mpp;
   int preSum = 0;
   int cnt = 0;
   mpp.insert({0,1}); // mpp[0] = 1

   for(int i=0; i<arr.size(); i++)
   {
      preSum += arr[i];
      int remove = preSum - k;
      cnt += mpp[remove];
      mpp[preSum] += 1;
   }

   cout << cnt;

}

int main()
{
   int k = 3;
   vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};

   Better(arr, k);
   Optimal(arr, k);

    
}