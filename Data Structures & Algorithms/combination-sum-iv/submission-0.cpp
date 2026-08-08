class Solution {
public:
    int solve(int index, int target, vector<int>& nums, vector<int>& dp) {

        if (target == 0)
            return 1;

        if (index == nums.size() || target < 0)
            return 0;

        // DP based on target
        if (dp[target] != -1)
            return dp[target];

        // Pick
        int pick = 0;
        if (nums[index] <= target) {
            pick = solve(0, target - nums[index], nums, dp);
        }

        // Not Pick
        int notPick = solve(index + 1, target, nums, dp);

        return dp[target] = pick + notPick;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);

        return solve(0, target, nums, dp);
    }
};