class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int add = 0;
        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    add++;
                }
            }
        }

        while(!st.empty()){
            add++;
            st.pop();
        }
        return add;
    }
};