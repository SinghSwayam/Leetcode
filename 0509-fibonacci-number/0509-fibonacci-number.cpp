class Solution {
public:
    // memoization
    int solveByMemo(int n, vector<int>& dp){
        if(n == 0 || n == 1){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = solveByMemo(n-1, dp) + solveByMemo(n-2,dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+1, -1);
        int ans = solveByMemo(n, dp);
        return ans;
    }
};