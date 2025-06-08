#include<iostream>
#include<vector>
using namespace std;

// Que: 

void brute(vector<int> arr)
{
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }

    int pv = pos.size();
    int nv = neg.size();
    int mini = min(pv,nv);

    for(int i=0; i<mini; i++)
    {
        arr[i*2] = pos[i];
        arr[(i*2) + 1] = neg[i];
    }

    for (int i = mini; i < pv; i++) {
        arr.push_back(pos[i]);
    }
    for (int i = mini; i < nv; i++) {
        arr.push_back(neg[i]);
    }

    

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
   

}

int main()
{
    brute({1,2,-4,5,3,6});
}