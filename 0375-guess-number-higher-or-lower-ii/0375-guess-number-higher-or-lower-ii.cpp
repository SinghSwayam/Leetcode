class Solution {
public:
    int solveRecursion(int s, int e){
        if(s >= e){
            return 0;
        }
        int mini = INT_MAX;
        for(int i=s; i<=e; i++){
            int curr = i + max(solveRecursion(s, i-1), solveRecursion(i+1, e));
            mini = min(mini, curr);
        }
        return mini;
    }

    int solveMemoization(int s, int e, vector<vector<int>>& dp){
        if(s >= e){
            return 0;
        }

        if(dp[s][e] != -1) return dp[s][e];

        int mini = INT_MAX;
        for(int i=s; i<=e; i++){
            int curr = i + max(solveMemoization(s, i-1, dp), solveMemoization(i+1, e, dp));
            mini = min(mini, curr);
        }
        return dp[s][e] = mini;
    }

    int solveTabulation(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int s=n; s>=1; s--){
            for(int e=s+1; e<=n; e++){
                int mini = INT_MAX;
                for(int i=s; i<=e; i++){
                    int curr = i + max(dp[s][i-1], dp[i+1][e]);
                    mini = min(mini, curr);
                }
                dp[s][e] = mini;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // int ans = solveRecursion(1, n);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); 
        // int ans = solveMemoization(1, n, dp);

        int ans = solveTabulation(n);
        return ans;
    }
};