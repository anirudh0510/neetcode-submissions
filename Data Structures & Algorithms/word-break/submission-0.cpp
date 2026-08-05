class Solution {
public:
    bool solve(int index, string &s, unordered_set<string> &dict,
               int n, vector<int> &dp) {

        if (index == n)
            return true;

        if (dp[index] != -1)
            return dp[index];

        string temp = "";

        for (int i = index; i < n; i++) {
            temp += s[i];

            if (dict.count(temp)) {
                if (solve(i + 1, s, dict, n, dp))
                    return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<int> dp(n, -1);

        return solve(0, s, dict, n, dp);
    }
};