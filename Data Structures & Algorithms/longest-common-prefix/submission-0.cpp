class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //compare characters column-wise , take the first string as the reference and compare its characters with the same position in every other string
        string ans = strs[0];
        for(int i = 1 ; i < strs.size() ; i++){
            int j = 0 ;
            while(j < ans.size() && j < strs[i].size() && ans[j] == strs[i][j]){
                j++;
            }
            ans = ans.substr(0,j);
            if(ans.empty())
                return "";
        }
        return ans;
    }
};