#include<iostream>
#include<vector>
using namespace std;

void Brute(vector<int> arr)
{
    int mis = -1;
    int rep = -1;
    
    for(int i=0; i<arr.size(); i++)
    {
        int flag = 0;
        for(int j=0; j<arr.size(); j++)
        {
            if(j > i && arr[i] == arr[j]) rep = arr[i];
            if(i+1 == arr[j]) flag++;
        }
        if(flag == 0) mis = i+1;
    }
    cout << rep << " " << mis;

    // TC: n*n
    // SC: 1
}

void Better(vector<int> arr)
{
    int n = arr.size();
    int mis = -1;
    int rep = -1;
    int hash[n+1] = {0};


    for(int i=0; i<arr.size(); i++)
    {
        hash[arr[i]]++;
    }
    for(int i=1; i<n+1; i++)
    {
        if(hash[i] == 2) rep = i;
        if(hash[i] == 0) mis = i;
    }
    cout << rep << " " << mis;

    // Logic: Using hash array
    //    TC: n
    //    SC: n
}

void Optimal1(vector<int> arr)
{
    int n = arr.size();
    int sum = 0;
    int sumSq = 0 ;
    int sum_ = n*(n+1)/2;
    int sumSq_ = n*(n+1)*(2*n+1)/6;


    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
        sumSq = sumSq + arr[i]*arr[i];
    }
    int eq1 = sum_ - sum; // mis - rep
    int eq2 = sumSq_ - sumSq; // (mis-rep)(mis+rep)
    int eq3 = eq2/eq1; // mis + rep

    int mis = (eq1 + eq3)/2;
    int rep = eq3 - mis;

    cout << rep << " " << mis;
    
    // Logic: find sum ans sum of squares and make equations;
    //    TC: n
    //    SC: 1
}

void Optimal2(vector<int> arr)
{
    int n = arr.size();
    int xor1 = 0;
    int xor2 = 0;
    int rep = 0;
    int mis = 0;

    for(int i=0; i<n; i++)
    {
        xor1 = xor1^arr[i];
        xor2 = xor2^(i+1);
    }
    int xor_ = xor1^xor2; // rep^mis
    int nth_bit = 0;
    int quo = xor_;
    while(1)
    {
        quo = quo/2;
        nth_bit++;
        if(quo%2 == 1) break;
        
    }
    
}

int main()
{
    vector<int> arr = {4,3,6,2,1,1};

    // Brute(arr);
    // cout << endl;
    // Better(arr);
    // cout << endl;
    // Optimal1(arr);
    // cout << endl;
    Optimal2(arr);
}
