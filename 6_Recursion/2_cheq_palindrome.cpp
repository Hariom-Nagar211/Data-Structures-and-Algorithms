#include<iostream>
using namespace std;

int arr[] = {8,7,1,2,3,2,1,7,8};
int n = 9; 

void check_palindrome(int a = 0)
{
    if(arr[a] == arr[n-a-1])
    {
        if(a >= n-a-1)
        {
            cout << "the array is a palindrome" << endl;
            return;
        }
        return check_palindrome(a+1);
    }
    else
    {
        cout << "the array is not a palindrome" << endl;
        return;
    }
}

int main()
{
    check_palindrome();
}



