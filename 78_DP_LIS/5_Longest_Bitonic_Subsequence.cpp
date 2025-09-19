
// Link : https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        if (n < 3) return 0; // Need at least 3 elements to be bitonic

        vector<int> inc(n, 1), dec(n, 1);

        // Longest Increasing Subsequence ending at i
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    inc[i] = max(inc[i], inc[j] + 1);
            }
        }

        // Longest Decreasing Subsequence starting at i
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i])
                    dec[i] = max(dec[i], dec[j] + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            // need at least one increasing step and one decreasing step
            if (inc[i] > 1 && dec[i] > 1)
                ans = max(ans, inc[i] + dec[i] - 1);
        }

        return ans;
    }
};
