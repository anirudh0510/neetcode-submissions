class Solution {
public:
    int solve(int i, string &s, int n, vector<int>& dp){

        dp[n] = 1;

        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }

            int only_ith_char = dp[i + 1];    //single digit characters

            int ith_and_ithplus1_char = 0;

            if(i + 1 < n &&
               (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){
                ith_and_ithplus1_char = dp[i + 2];
            }

            dp[i] = only_ith_char + ith_and_ithplus1_char;
        }

        return dp[0];
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 2, 0);
        return solve(0, s, n, dp);
    }
};