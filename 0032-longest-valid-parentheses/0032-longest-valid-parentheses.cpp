class Solution {
    int solve(string str){
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i=0; i<str.length(); i++){
            if(str[i] == '(') {
               st.push(i);
            }
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else{
                    ans = max(ans, i-st.top());
                }
            }
        }
        return ans;
    }
public:
    int longestValidParentheses(string s) {
        return solve(s);
    }
};