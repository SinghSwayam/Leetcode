class Solution {
public:
    bool checkString(string s) {
        int bstart = -1;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'b'){
                bstart = i;
                break;
            }
        }

        if(bstart == -1) return true;

        for(int i=bstart; i<s.size(); i++){
            if(s[i] == 'a'){
                return false;
            }
        }

        return true;
    }
};