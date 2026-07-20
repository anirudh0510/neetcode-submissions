class Solution {
public:
    bool solve(int index, vector<int>& bucket, vector<int>& nums, int target, int k) {

        // Base case: all numbers are placed
        if (index == nums.size()) {
            return true;
        }

        // Try placing nums[index] into every bucket
        for (int i = 0; i < k; i++) {

            // Skip if this bucket exceeds target
            if (bucket[i] + nums[index] > target)
                continue;

            // Do
            bucket[i] += nums[index];

            // Explore
            if (solve(index + 1, bucket, nums, target, k))
                return true;

            // Undo
            bucket[i] -= nums[index];

            // Optimization:
            // If we tried an empty bucket and it didn't work,
            // don't try other empty buckets.
            if (bucket[i] == 0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % k != 0)
            return false;

        int target = sum / k;

        // Largest numbers first (important optimization)
        sort(nums.rbegin(), nums.rend());

        // If the largest element itself is bigger than target
        if (nums[0] > target)
            return false;

        vector<int> bucket(k, 0);

        return solve(0, bucket, nums, target, k);
    }
};