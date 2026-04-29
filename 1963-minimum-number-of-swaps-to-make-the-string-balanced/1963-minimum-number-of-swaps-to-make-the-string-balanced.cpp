class Solution {
public:
    int minSwaps(string s) {
        int open=0;
        int imbalance=0;
        for(char ch : s){
            if(ch == '['){
                open++;
            }else{
                if(open > 0)
                    open--;
                else
                    imbalance++;
            }
        }
        
        int ans = (imbalance + 1) / 2;
        return ans;
    }
};