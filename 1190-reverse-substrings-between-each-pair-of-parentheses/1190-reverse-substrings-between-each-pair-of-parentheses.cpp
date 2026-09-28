class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        
        for(char ch : s){
            if(ch != ')'){
                st.push(ch);
            }else{
                string curr = "";
                while(st.top() != '('){
                    curr.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(char curr_ch : curr){
                    st.push(curr_ch);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};