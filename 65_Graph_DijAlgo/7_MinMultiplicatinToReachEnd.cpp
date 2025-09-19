#include <bits/stdc++.h>
using namespace std;

int MinMultiplication(vector<int> &arr, int start, int end)
{
   {
      int n = arr.size();
      queue<pair<int, int>> q;
      vector<int> dist(100000, INT_MAX);
      dist[start] = 0;
      q.push({start, 0});

      while (!q.empty())
      {
         int node = q.front().first;
         int dis = q.front().second;
         q.pop();

         for (auto it : arr)
         {
            int adjNode = (node * it) % 100000;
            if (dis + 1 < dist[adjNode])
            {
               dist[adjNode] = dis + 1;
               if (adjNode == end)
                  return dis + 1;

               q.push({adjNode, dist[adjNode]});
            }
         }
      }
      if (start == end)
         return 0;
      return -1;
   }
}
