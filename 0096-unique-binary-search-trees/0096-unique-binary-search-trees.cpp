class Solution {
public:
    int solveRec(int n){
        if(n <= 1) return 1;

        int total = 0;
        for(int root=1; root<=n; root++){
            int left = solveRec(root-1);
            int right = solveRec(n-root);

            total += left*right;
        }
        return total;
    }

    int solveMemo(int n, vector<int>& dp){
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];

        int total = 0;
        for(int root=1; root<=n; root++){
            int left = solveMemo(root-1, dp);
            int right = solveMemo(n-root, dp);

            total += left*right;
        }

        return dp[n] = total;
    }

    int numTrees(int n) {
        // return solveRec(n);

        vector<int> dp(n+1, -1);
        return solveMemo(n, dp);
    }
};