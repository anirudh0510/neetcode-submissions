class Solution {
public:
    int solve(int index, int n, vector<vector<int>>& dp) {

        if (n == 0)
            return 0;

        if (index * index > n)
            return 1e9;

        if (dp[index][n] != -1)
            return dp[index][n];

        // Pick
        int pick = 1 + solve(index, n - index * index, dp);

        // Not Pick
        int notPick = solve(index + 1, n, dp);

        return dp[index][n] = min(pick, notPick);
    }

    int numSquares(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(1, n, dp);
    }
};