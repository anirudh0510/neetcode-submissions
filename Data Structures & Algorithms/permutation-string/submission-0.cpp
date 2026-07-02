class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m)return false;

        vector<int>s1_freq(26,0);
        vector<int>s2_freq(26,0);

        int l=0;
        int r=0;
        for(auto &ch:s1){
            s1_freq[ch-'a']++;
        }
        while(r<m){
            s2_freq[s2[r]-'a']++;

            if(r - l +1 >n ){
                s2_freq[s2[l]-'a']--;
                l++;
            }
            if(s1_freq == s2_freq)return true;
            r++;
        }
        return false;
    }
};