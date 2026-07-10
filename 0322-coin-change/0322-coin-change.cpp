class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int amount){
        // base case
        if(amount == 0) return 0;

        int mini = INT_MAX;
        int n = coins.size();
        for(int i=0; i<n; i++){
            // find ans using ith coin
            if(amount - coins[i] >= 0){
                int recAns = solveUsingRecursion(coins, amount - coins[i]);
                // valid ans
                if(recAns != INT_MAX){
                    int ans = 1 + recAns;
                    mini = min(mini, ans);
                }
            }
        }
        return mini;
    }

    int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp){
        // base case
        if(amount == 0) return 0;

        if(dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;
        int n = coins.size();
        for(int i=0; i<n; i++){
            // find ans using ith coin
            if(amount - coins[i] >= 0){
                int recAns = solveUsingMem(coins, amount - coins[i], dp);
                // valid ans
                if(recAns != INT_MAX){
                    int ans = 1 + recAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n+1, -1);
        int ans =  solveUsingMem(coins, amount, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};