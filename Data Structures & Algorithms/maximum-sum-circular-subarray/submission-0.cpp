class Solution {
public:
    int solve(vector<int>&nums){
        int total = 0;
        int currMax = 0;
        int maxSum = INT_MIN;

        int currMin = 0;
        int minSum = INT_MAX;

        for(int i=0 ; i<nums.size() ; i++){
            //normal kadanes
            currMax = max(nums[i] , currMax + nums[i]);
            maxSum = max(maxSum , currMax);

            //minumum kadanes , if first and last element are including in cicular manner by chance in ans .  for that we have to Tota - minSumArray ;
            currMin = min(nums[i] , currMin + nums[i]);
            minSum = min(minSum , currMin);
            total += nums[i];
        }

        //if all elements are negative
        if(maxSum < 0 ){
            return maxSum;
        }
        //the final ans is from normal kadanes or , case:2 that circular array is giving the maxsum
        return max(maxSum , total - minSum);
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        return solve(nums);
    }
};