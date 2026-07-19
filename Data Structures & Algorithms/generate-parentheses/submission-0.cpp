class Solution {
public:
    bool isValid(string s){
        int balance = 0;

        for(char c : s){
            if(c=='(')
                balance++;
            else
                balance--;

            if(balance<0)
                return false;
        }

        return balance==0;
    }

    void solve(int n, vector<string>& ans, string& ds){

        if(ds.size()==2*n){
            if(isValid(ds))
                ans.push_back(ds);
            return;
        }

        ds.push_back('(');
        solve(n,ans,ds);
        ds.pop_back();

        ds.push_back(')');
        solve(n,ans,ds);
        ds.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds;

        solve(n,ans,ds);

        return ans;
    }
};