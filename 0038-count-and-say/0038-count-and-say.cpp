class Solution {
public:
    string countAndGenerate(string s){
        int count = 1;
        int i=1;
        string temp="";

        for(i;i<s.size();i++){
            if(s[i] != s[i-1]){
                temp += to_string(count);
                temp += s[i-1];
                count =1;
            }else{
                count++;
            }

        }
        temp += to_string(count);
        temp += s[i-1];

        return temp;
    }

    string countAndSay(int n) {
        string ans="1";
        while(--n){
            ans = countAndGenerate(ans);
        }

        return ans;
    }
};