class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // for every string , sort the string -> use sorted string as key -> put original string into key's vector

        unordered_map<string , vector<string>>mpp;
        for(int i = 0 ; i < strs.size() ; i++){
            string key = strs[i];
            sort(key.begin() , key.end());

            mpp[key].push_back(strs[i]);
        }

        vector<vector<string>>ans;
        for(auto &it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};