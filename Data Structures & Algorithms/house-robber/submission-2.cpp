class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // dp[i] = maximum money that can be robbed starting from house i
        vector<int> dp(n + 2, 0);

        // Base cases:
        // dp[n] = 0
        // dp[n + 1] = 0

        for (int i = n - 1; i >= 0; i--) {
            int rob = nums[i] + dp[i + 2];
            int skip = dp[i + 1];

            dp[i] = max(rob, skip);
        }

        return dp[0];
    }
};