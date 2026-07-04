class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string i : tokens){
            if(i == "+"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(first+second);
            }
            else if(i == "*"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(first * second);
            }
            else if(i == "-"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second - first);
            }
            else if(i == "/"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second / first);
            }
            else {
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};