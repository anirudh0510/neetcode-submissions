class Solution {
public:
    bool solve(int i, int j, string &s1, string &s2, string &s3,
               vector<vector<int>> &dp) {

        int k = i + j;

        // All characters of s3 used
        if (k == s3.size()) {
            return true;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool result = false;

        // Pick from s1
        if (i < s1.size() && s1[i] == s3[k]) {
            result = solve(i + 1, j, s1, s2, s3, dp);
        }

        // Pick from s2
        if (!result && j < s2.size() && s2[j] == s3[k]) {
            result = solve(i, j + 1, s1, s2, s3, dp);
        }

        return dp[i][j] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        vector<vector<int>> dp(
            s1.size() + 1,
            vector<int>(s2.size() + 1, -1)
        );

        return solve(0, 0, s1, s2, s3, dp);
    }
};