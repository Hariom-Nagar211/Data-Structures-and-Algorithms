#include<iostream>
using namespace std;

// Que: WAP to sort an array using bubble sort.

void bubbleSort(int arr[], int n) 
{
    bool swapped;
    for (int i = 0; i < n - 1; i++) 
    {
        swapped = false; // To optimize and stop if no swaps occur
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]); // Swap adjacent elements
                swapped = true;
            }
        }
        // If no swaps happened, the array is already sorted
        if (!swapped) break;
    }

    // TC : Best Case : N^2, Wrost Case : N^2, Avg. Case : N^2
    // SC : 1
}


