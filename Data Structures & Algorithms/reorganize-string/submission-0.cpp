class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        
        for(char c : s) freq[c]++;
        
        priority_queue<pair<int, char>> pq;
        for(auto it : freq) {
            pq.push({it.second, it.first});
        }
        
        string ans = "";
        
        while(pq.size() > 1) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();
            
            ans += c1;
            ans += c2;
            
            if(--f1 > 0) pq.push({f1, c1});
            if(--f2 > 0) pq.push({f2, c2});
        }
        
        // If one character left
        if(!pq.empty()) {
            auto [f, c] = pq.top();
            if(f > 1) return "";
            ans += c;
        }
        
        return ans;
    }
};