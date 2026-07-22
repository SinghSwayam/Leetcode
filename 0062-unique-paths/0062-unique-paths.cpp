class Solution {
public:
    int solveRecursion(int m ,int n){
        if(m == 0 || n == 0) return 0;

        if(m == 1 && n == 1) return 1;

        int down = solveRecursion(m-1, n);
        int right = solveRecursion(m, n-1);

        return down + right;
    }

    int solveMemoization(int m ,int n, vector<vector<int>>& dp){
        if(m == 0 || n == 0) return 0;

        if(m == 1 && n == 1) return 1;

        if(dp[m][n] != -1) return dp[m][n];

        int down = solveMemoization(m-1, n, dp);
        int right = solveMemoization(m, n-1, dp);

        return dp[m][n] = down + right;
    }

    int uniquePaths(int m, int n) {
        // int ans = solveRecursion(m, n);

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int ans = solveMemoization(m, n, dp);

        return ans;
    }
};