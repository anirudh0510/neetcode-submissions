class Solution {
public:
    bool f(int indx, int target, vector<int>& nums,
           vector<vector<int>>& dp) {

        if (target == 0) return true;
        if (indx == 0) return nums[0] == target;

        if (dp[indx][target] != -1)
            return dp[indx][target];

        bool notTake = f(indx - 1, target, nums, dp);

        bool take = false;
        if (target >= nums[indx])
            take = f(indx - 1, target - nums[indx], nums, dp);

        return dp[indx][target] = (take || notTake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2) return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, nums, dp);
    }
};