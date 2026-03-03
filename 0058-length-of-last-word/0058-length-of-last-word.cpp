class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();

        int e=len-1;

        while(e >= 0 && s[e] == ' '){
            e--;
        }
        int count = 0;
        while(e >= 0 && s[e] != ' '){
            count++;
            e--;
        }

        return count;
    }
};