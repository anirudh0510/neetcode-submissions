class Solution {
public:
    void Neighbours(queue<string>& q, string& curr, unordered_set<string>& st) {
        for (int i = 0; i < 4; i++) {
            char ch = curr[i];
            char dec = (ch == '0') ? '9' : ch - 1;
            char inc = (ch == '9') ? '0' : ch + 1;

            curr[i] = dec;
            if (st.find(curr) == st.end()) {
                st.insert(curr);
                q.push(curr);
            }
            curr[i] = inc;
            if (st.find(curr) == st.end()) {
                st.insert(curr);
                q.push(curr);
            }

            curr[i] = ch; // restore
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        string start = "0000";

        if (st.count(start)) return -1;      // fix 5
        if (start == target) return 0;        // handle trivial case

        queue<string> q;
        q.push(start);
        st.insert(start);                     // mark visited

        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();

                if (curr == target) {         // fix 4
                    return level;
                }

                Neighbours(q, curr, st);       // fix 3
            }
            level++;
        }
        return -1;                            // fix 6
    }
};