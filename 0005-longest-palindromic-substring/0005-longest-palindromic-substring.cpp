class Solution {
public:
    int expand(string& s,int i,int j){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }

    string longestPalindrome(string s) {
        int start=0;
        int end=0;

        for(int i=0;i<s.size();i++){
            int oddLen = expand(s,i,i);
            int evenLen = expand(s,i,i+1);

            int len = max(oddLen,evenLen);

            if(len > end-start){
                start = i - (len-1)/2;
                end = i+len/2;
            }

        }
        
        return s.substr(start, end-start+1);
    }
};