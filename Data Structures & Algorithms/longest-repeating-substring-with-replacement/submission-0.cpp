class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> mpp;

        int n = s.size();
        int l = 0;
        int r = 0;
        int maxfreq = 0;
        int ans = 0;

        while(r < n){

            mpp[s[r]]++;
            maxfreq = max(maxfreq, mpp[s[r]]);

            while((r-l+1) - maxfreq > k){

                mpp[s[l]]--;
                l++;

                maxfreq = 0;
                for(auto &p : mpp)
                    maxfreq = max(maxfreq, p.second);
            }

            ans = max(ans, r-l+1);

            r++;
        }

        return ans;
    }
};