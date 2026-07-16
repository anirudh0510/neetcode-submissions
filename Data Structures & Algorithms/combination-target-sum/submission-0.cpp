class Solution {
public:
    void Solve(int idx,int target , vector<int>&candidates, vector<vector<int>>&ans, vector<int>&ds){

        //base casse
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
            //take it
            if(candidates[idx]<=target){
                ds.push_back(candidates[idx]);
                Solve(idx , target-candidates[idx],candidates,ans,ds);
                ds.pop_back();
            }

            //dont take it
            Solve(idx+1 , target, candidates,ans,ds);


            

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        Solve(0,target,candidates,ans,ds);
        return ans;
    }
};