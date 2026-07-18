class Solution {
public:
    void solve(int index , int n , vector<int>&nums , vector<vector<int>>&ans){
        if(index == n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st; 
        for(int i=index ; i<n ; i++){

            if (st.count(nums[i])) continue;   // Skip duplicates

            st.insert(nums[i]);
            
            swap(nums[i],nums[index]);
            solve(index+1 , n,nums ,ans);
            swap(nums[index] , nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        solve(0 , n , nums  , ans);
        return ans;
    }
};