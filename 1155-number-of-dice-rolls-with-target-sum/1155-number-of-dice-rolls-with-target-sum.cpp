class Solution {
    const int mod = 1e9+7;

public:
    int solveRec(int n, int k, int target){
        if(n == 0 && target == 0) return 1;
        if(n != 0 && target == 0) return 0;
        if(n == 0 && target != 0) return 0;

        int ans = 0;
        for(int i=1;i<=k;i++){
            ans = (ans + solveRec(n-1,k,target-i)) % mod;
        }

        return ans;
    }

    int solveMemo(int n, int k, int target, vector<vector<int>>& dp){
        if(n == 0 && target == 0) return 1;
        if(n != 0 && target == 0) return 0;
        if(n == 0 && target != 0) return 0;
        if(target < 0) return 0;

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        int ans = 0;
        for(int i=1;i<=k;i++){
            int temp = solveMemo(n-1, k, target-i, dp) % mod;
            ans = (ans + temp) % mod;
        }

        return dp[n][target] = ans;
    }

    int solveTab(int n, int k, int target){
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        dp[0][0] = 1;

        for(int n_idx = 1; n_idx<=n; n_idx++){
            for(int t_idx = 1; t_idx <= target; t_idx++){

                int ans = 0;
                for(int i=1; i<=k && i <= t_idx ;i++){
                    int temp = dp[n_idx-1][t_idx-i]% mod;
                    ans = (ans + temp) % mod;
                }
                dp[n_idx][t_idx] = ans;

            }
        }
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // return solveRec(n, k, target);

        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return solveMemo(n, k, target, dp);

        return solveTab(n, k, target);
    }
};