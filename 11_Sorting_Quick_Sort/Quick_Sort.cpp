#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) 
{
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low; // Pointer for smaller element

    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            swap(arr[i], arr[j]); // Swap elements
            i++; 
        }
    }
    swap(arr[i], arr[high]); // Place pivot in correct position
    return i; // Return pivot index
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high); // Partition the array

        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

    // TC : Best & Average Case: O(N log N), Worst Case: O(N²) (when the pivot is the smallest or largest element)
    // SC : O(log N) (due to recursion stack)

}