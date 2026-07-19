class Solution {
public:
    vector<string> mp = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void solve(int index, string &ds, vector<string> &ans, string &digits) {
        if (index >= digits.length()) {
            ans.push_back(ds);
            return;
        }

        char ch = digits[index];
        string str = mp[ch - '0'];

        for (int i = 0; i < str.length(); i++) {
            ds.push_back(str[i]);              // Do
            solve(index + 1, ds, ans, digits); // Explore
            ds.pop_back();                     // Undo
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;

        string ds;
        solve(0, ds, ans, digits);
        return ans;
    }
};