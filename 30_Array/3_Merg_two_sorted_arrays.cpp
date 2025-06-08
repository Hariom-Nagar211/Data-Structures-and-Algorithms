#include <bits/stdc++.h>
using namespace std;

void Optimal1(vector<int> arr1, vector<int> arr2)
{
    int n1 = 4;
    int n2 = 5;
    int i = n1 - 1;
    int j = 0;

    while (i >= 0 && j < n2)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
            i--;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }

    // TC: min(n1,n2) + n1logn1 + n2logn2
    // SC: 1
}

void Optimal2(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int len = n1 + n2;
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int i = 0;
        int j = i + gap;

        while (j < len)
        {
            // arr1, arr1
            if (i < n1 && j < n1)
            {
                if (arr1[i] < arr1[j])
                {
                    swap(arr1[i], arr1[j]);
                }
            }

            // arr1, arr2
            else if (i < n1 && j >= n1)
            {
                if (arr1[i] < arr2[j % n1])
                {
                    swap(arr1[i], arr2[j % n1]);
                }
            }

            // arr2,arr2
            else
            {
                if (arr2[i % n1] < arr2[j % n2])
                {
                    swap(arr2[i % n1], arr2[j % n1]);
                }
            }
            i++;
            j++;

            if (gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }
    }

    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }

    // Logic: gap method
    //    TC: log(n1+n2) * (n1+n2)
    //    SC: 1
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 4, 8, 9};

    Optimal1(arr1, arr2);
    cout << endl;
    Optimal1(arr1, arr2);
}