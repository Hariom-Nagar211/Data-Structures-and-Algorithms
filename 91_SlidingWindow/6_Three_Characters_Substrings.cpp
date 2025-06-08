#include<iostream>
using namespace std;

// QUE : Find the total number of substring contaning all the unique characters int the string. // abacabba

// Brute force
int f(string s = "bbacba", int n = 6)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        int arr[3] = {0};
        for(int j=i; j<n; j++)
        {
            if(arr[s[j] - 'a'] == 0) arr[s[j] - 'a'] = 1;

            if(arr[0] + arr[1] + arr[2] == 3)
            {
                cnt += n - j;
                break;
            }
        }
    }
    return cnt;
}

// Optimal
int f2(string s = "bbacba", int n = 6)
{
    int cnt = 0;
    int arr[3] = {-1, -1, -1};
    for(int i = 0; i<n; i++)
    {
        arr[s[i] - 'a'] = i;

        if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1)
        {
            int mini = min(arr[0], min(arr[1], arr[2]));
            cnt += mini+1;
        }
    }
    return cnt;
}

int main()
{
    cout << f() << endl << f2() << endl;
}