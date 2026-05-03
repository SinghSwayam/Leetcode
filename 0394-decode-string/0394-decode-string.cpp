class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch:s){
            if(ch == ']'){
                string repeat="";
                while(!st.empty() && !isdigit(st.top()[0])){
                    repeat += st.top() == "["? "" : st.top();
                    st.pop();
                }

                string num = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());

                int n = stoi(num);
                string decode="";
                while(n--){
                    decode += repeat;
                }
                st.push(decode);

            }else{
                string temp(1,ch);
                st.push(temp);
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};