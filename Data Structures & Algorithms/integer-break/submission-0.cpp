class Solution {
public:
    int solve(int n, vector<int>& dp) {

        // If n is 1, we cannot break it further
        if (n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int ans = 0;

        // Try breaking n into i + (n-i)
        for (int i = 1; i < n; i++) {

            // Don't break (n-i) further
            int notBreak = i * (n - i);

            // Break (n-i) further
            int breakMore = i * solve(n - i, dp);

            ans = max(ans, max(notBreak, breakMore));
        }

        return dp[n] = ans;
    }

    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};