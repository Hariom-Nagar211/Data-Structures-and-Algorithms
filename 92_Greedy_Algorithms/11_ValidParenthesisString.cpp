#include<bits/stdc++.h>
using namespace std;

// Problem Statment: Valid Parenthesis String

// LC:
// TC:
// SC:

bool f(string s)
{
    int n = s.size();
    int low = 0, high = 0; // low: minimum open parentheses, high: maximum open parentheses

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            low++;
            high++;
        }
        else if (s[i] == ')')
        {
            low = max(low - 1, 0);
            high--;
        }
        else // s[i] == '*'
        {
            low = max(low - 1, 0);
            high++;
        }

        if (high < 0) return false; // Too many closing parentheses
    }

    return low == 0; // Valid if all open parentheses are matched
}

int main()
{
    cout << f("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())") << endl;
}