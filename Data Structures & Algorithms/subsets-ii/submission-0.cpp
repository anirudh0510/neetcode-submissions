class Solution {
public:
    void solve(int index, int n, vector<int>& ds,
               vector<vector<int>>& ans, vector<int>& nums) {

        if (index == n) {
            ans.push_back(ds);
            return;
        }

        // Pick
        ds.push_back(nums[index]);
        solve(index + 1, n, ds, ans, nums);
        ds.pop_back();

        // Skip all duplicates
        while (index + 1 < n && nums[index] == nums[index + 1])
            index++;

        // Not Pick
        solve(index + 1, n, ds, ans, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, nums.size(), ds, ans, nums);

        return ans;
    }
};