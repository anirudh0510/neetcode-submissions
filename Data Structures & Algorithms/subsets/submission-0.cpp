class Solution {
public:
    vector<vector<int>> solve(int index ,int n, vector<int>&temp, vector<vector<int>>&ans ,  vector<int>&nums){
        if(index==n){
            ans.push_back(temp);
            return ans;
        }
        //take
        temp.push_back(nums[index]);
        solve(index+1 , n , temp , ans ,  nums);
        temp.pop_back();
        //not take
        solve(index+1 , n , temp , ans , nums);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        vector<vector<int>>ans;
        solve(0 ,n, temp , ans ,nums);
        return ans;
    }
};