class Solution {
public:
    int solve(vector<int>& nums, int i, int Xor) {
        if (i == nums.size()) {
            return Xor;
        }

        // Include current element
        int include = solve(nums, i + 1, Xor ^ nums[i]);

        // Exclude current element
        int exclude = solve(nums, i + 1, Xor);

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};