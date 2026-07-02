class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {

            if (mp.count(s[r])) {
                l = max(l, mp[s[r]] + 1);
            }

            mp[s[r]] = r;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};