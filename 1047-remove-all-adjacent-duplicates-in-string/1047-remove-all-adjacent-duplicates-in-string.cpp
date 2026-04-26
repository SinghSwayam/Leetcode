class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto curr : s){
            if(st.empty()){
                st.push(curr);
            }else{
                if(st.top() == curr){
                    st.pop();
                }else{
                    st.push(curr);
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