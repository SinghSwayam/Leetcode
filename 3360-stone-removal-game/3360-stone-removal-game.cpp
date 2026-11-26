class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;
        int i=10;
        while(n >= 0){
            n -= i;
            if(n < 0){
                return false;
            }
            --i;
            
            n -= i;
            if(n < 0){
                return true;
            }
            --i;
        }
        
        return false;
    }
};