class Solution {
public:
    void solve(int index, int n, int k,
               vector<int>& ds,
               vector<vector<int>>& ans) {

        if (k == 0) {
            ans.push_back(ds);
            return;
        }

        if (index > n)
            return;

        // Pick
        ds.push_back(index);
        solve(index + 1, n, k - 1, ds, ans);
        ds.pop_back();

        // Not Pick
        solve(index + 1, n, k, ds, ans);
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> ds;

        solve(1, n, k, ds, ans);

        return ans;
    }
};