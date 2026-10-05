class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char c : s){
            if(c == '('){
                st.push(0);
            }else{
                int inner = st.top();
                st.pop();

                int val = (inner == 0) ? 1 : 2*inner;
                st.top() += val;
            }
        }
        return st.top();
    }
};