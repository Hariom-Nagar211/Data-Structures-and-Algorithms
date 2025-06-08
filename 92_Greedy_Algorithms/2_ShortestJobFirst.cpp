#include<bits/stdc++.h>
using namespace std;

// Problem Statment: Calculates the average waiting time for Shortest Job First (SJF) scheduling.

// LC: Greedy Algorithm(Sorting)
// TC: O(N logN)
// SC: O(1)

float AvgWatingTimeOfSJF(vector<int> processes)
{
    int n = processes.size();

    sort(processes.begin(), processes.end());

    int totalWT = 0;
    for(int i=0; i<n; i++)
    {
        totalWT += (totalWT + processes[i]);
    }

    float avgWT = (float)totalWT/(float)n;

    return avgWT;
}