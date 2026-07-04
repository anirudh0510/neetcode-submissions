class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {

            if (asteroid > 0) {
                st.push(asteroid);
            } 
            else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroid)) {
                    st.pop();
                }

                if (!st.empty() && st.top() == abs(asteroid)) {
                    st.pop();
                }
                else if (st.empty() || st.top() < 0) {
                    st.push(asteroid);
                }
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};