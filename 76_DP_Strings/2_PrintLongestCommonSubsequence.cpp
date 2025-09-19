#include<bits/stdc++.h>
using namespace std;

// Note : you have to use padding to solve this problem
// QUE : Print the longest comman string among the two given strings.
// Link : https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

// The function now correctly takes and returns a vector of integers
vector<int> longestCommonSubsequence(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    int m = b.size();

    // Using a 1-indexed DP table simplifies the code and avoids out-of-bounds errors.
    // dp[i][j] will store the length of the LCS of a[0...i-1] and b[0...j-1].
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Step 1: Fill the DP table to find the length of the LCS
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // If the current elements match, they are part of the LCS.
            // We add 1 to the length of the LCS of the preceding subsequences.
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } 
            // If they don't match, the LCS length is the maximum of the two possibilities:
            // 1. Excluding the current element from 'a' (dp[i-1][j])
            // 2. Excluding the current element from 'b' (dp[i][j-1])
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Step 2: Reconstruct the LCS by backtracking from the end of the DP table
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        // If the elements at the current positions (i-1 in 'a', j-1 in 'b') match,
        // this element is part of the LCS.
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            i--; // Move diagonally up-left
            j--;
        } 
        // If the elements don't match, move in the direction of the larger
        // LCS length in the DP table.
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // Move up
        } else {
            j--; // Move left
        }
    }

    // The LCS is built in reverse order, so we reverse it to get the correct sequence.
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> ans = longestCommonSubsequence(a, b);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}