class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> dp(n, false);
        dp[0] = true;

        int count = 0;

        for (int i = 1; i < n; i++) {

            // Add i - minJump into window
            int add = i - minJump;

            if (add >= 0 && dp[add]) {
                count++;
            }

            // Remove i - maxJump - 1 from window
            int remove = i - maxJump - 1;

            if (remove >= 0 && dp[remove]) {
                count--;
            }

            // i is reachable if there is at least
            // one reachable position in its jump range
            if (s[i] == '0' && count > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};