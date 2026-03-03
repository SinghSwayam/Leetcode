class Solution {
public:
    bool isPalindrome(string s) {
        
        string newS = "";
        for(int i=0;i<s.length();i++){
            if( (s[i] >='a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z') || (s[i] >='0' && s[i] <= '9')){
                if((s[i] >='A' && s[i] <= 'Z')){
                    newS.push_back(s[i] - 'A' + 'a');
                }else{
                    newS.push_back(s[i]);
                }
            }else{
                continue;
            }
        }

        int i=0;
        int j=newS.length()-1;

        while(i<=j){
            if(newS[i]!=newS[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;

    }
};