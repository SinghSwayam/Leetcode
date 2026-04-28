class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0) return 0;
        stack<int> st;
        int maxLength = 0;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    int len = i - st.top();
                    maxLength = max(len,maxLength);
                }
            }
        }

        return maxLength;
    }
};