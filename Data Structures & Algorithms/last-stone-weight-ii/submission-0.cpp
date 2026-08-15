class Solution {
public:
    int solve(int index, int sum, vector<int>& stones, int target,
              vector<vector<int>>& dp) {
        
        // Base case
        if (index == stones.size()) {
            return sum;
        }

        // Already calculated
        if (dp[index][sum] != -1) {
            return dp[index][sum];
        }

        // Don't pick current stone
        int notPick = solve(index + 1, sum, stones, target, dp);

        // Pick current stone if we don't cross target
        int pick = 0;
        if (sum + stones[index] <= target) {
            pick = solve(index + 1, sum + stones[index],
                         stones, target, dp);
        }

        return dp[index][sum] = max(pick, notPick);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;

        for (int x : stones) {
            total += x;
        }

        int target = total / 2;

        vector<vector<int>> dp(
            stones.size(),
            vector<int>(target + 1, -1)
        );

        int best = solve(0, 0, stones, target, dp);

        return total - 2 * best;
    }
};