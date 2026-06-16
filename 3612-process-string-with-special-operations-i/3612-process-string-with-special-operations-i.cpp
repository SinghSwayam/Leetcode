class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string res = "";
        for(char ch : s){
            if(ch == '*'){
                if(res.size() > 0){
                    res.pop_back();
                }
            }else if(ch == '#'){
                res += res;
            }else if(ch == '%'){
                reverse(res.begin(),res.end());
            }else{
                res.push_back(ch);
            }
        }
        return res;
    }
};