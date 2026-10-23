class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        if (dividend == INT_MAX && divisor == -1)
            return -dividend;

        if(divisor == 1){
            return dividend;
        }

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        bool sign = 1;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            sign = 0;
        }

        int ans = 0;
        while(n >= d){
            int cnt = 0;
            while(n >= (d << cnt+1)){
                cnt++;
            }

            ans += (1LL << cnt);
            n -= (d << cnt);
        }

        if(ans >= INT_MAX && sign == 1){
            return INT_MAX;
        }else if(ans >= INT_MAX && sign == 0){
            return INT_MIN;
        }

        return sign ? ans : -ans;
    }
};