#include<iostream>
using namespace std;

// Hashing: Prestoring/Fetching

// Que: Find the number of times a number appear in an array.

// Method 1 : Much time complicity bec of again and again iteration.

int cnt = 0;
int arr[100];
int n;
int p;

void count_num1(int num)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == num)
        {
            cnt++;
        }      
    }
    cout << cnt;
}

 
// Method 2: Less time complixity

void count_num2(int num)
{
    int hash[15] = {0};
    for(int i=0; i<n; i++)
    {
        int temp = arr[i]; // or hash[arr[i]]++
        hash[temp]++;
    }
        cout <<  p << " occured " << hash[num] << " times.";

}


int main()
{ 
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter number: ";
    cin >> p;
//   count_num1(p);
//   count_num2(p);

}

void Logic1()
 {
    // Iterate through the array
 } 

void Logic2()
 {
    // Using a null array.
 } 



// Note : Maximun size of int array that can be decleared inside main is 10^6
//        and maximun size of int array that can be decleared globally is 10^7.







