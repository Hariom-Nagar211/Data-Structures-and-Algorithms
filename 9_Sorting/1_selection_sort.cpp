#include<iostream>
using namespace std;

// Que: WAP to sort an array using selection sort. 

void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;  // Assume the first element is the smallest

        // Find the index of the smallest element in the remaining array
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }

        // Swap the smallest element with the first element of the unsorted part
        swap(arr[i], arr[minIndex]);
    }

    // TC : Best Case : N^2, Wrost Case : N^2, Avg. Case : N^2
    // SC : 1
}

