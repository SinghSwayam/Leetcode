class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int mod = 1e9+7;
        r -= l;
        vector<int> dp(r + 1, 1);
        
        for (int i = 1; i < n; i++) {
            int pre = 0;
            if (i % 2 != 0) {
                for (int v = 0; v <= r; v++) {
                    int pre2 = (pre + dp[v]) % mod;
                    dp[v] = pre;
                    pre = pre2;
                }
            } else {
                for (int v = r; v >= 0; v--) {
                    int pre2 = (pre + dp[v]) % mod;
                    dp[v] = pre;
                    pre = pre2;
                }
            }
        }
        
        int res = 0;
        for (int v : dp) {
            res = (res + v) % mod;
        }
        
        return (res * 2LL) % mod;
    }
};