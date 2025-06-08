#include<iostream>
using namespace std;

// Que : WAP to sort an array using insertion sort.

void Logic()
{
    // Take an element and place it in its correct order.(shift elements)
}

void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];  // The element to be placed correctly
        int j = i - 1;

        // Move elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Place key at its correct position
    }

    // TC : Best Case : N, Wrost Case : N^2, Avg. Case : N^2
    // SC : 1 
}

int main()
{
    int n;
    cout << "enter size: ";
    cin >> n;

    int arr[n];
    cout << "enter array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }


    insertion_sort(arr, n);
}

// Note : to cheak time complexity you can print a string every time the 
//        code runs.

// TC : O(n) ---> best case and O(n^2) ---> wrost case