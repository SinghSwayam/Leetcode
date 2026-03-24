class Solution {
public:
    long long fastExp(long long num,long long pow){
        long long ans=1;
        while(pow > 0){
            if(pow & 1){
                ans *= num;
            }
            num = num*num;
            pow >>= 1;
        }

        return ans;
    }

    int titleToNumber(string columnTitle) {
        int ans=0;
        int count = 0;
        for(int i=columnTitle.size()-1;i>=0;i--){
            ans = ans + ((columnTitle[i] - 'A' + 1) * fastExp(26,count));
            count++;
        }

        return ans;
    }
};