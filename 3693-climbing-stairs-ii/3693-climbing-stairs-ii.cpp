class Solution {
public:
    int solveRec(int i, int n, vector<int>& costs){
        if(i == n) return 0;

        int ans = INT_MAX;

        for(int j=i+1; j<= min(n, i+3); j++){
            int jcost = costs[j-1] + (j-i) * (j-i);

            ans = min(ans, jcost + solveRec(j, n, costs));
        }

        return ans;
    }

    int solveMemo(int i, int n, vector<int>& costs, vector<int>& dp){
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for(int j=i+1; j<= min(n, i+3); j++){
            int jcost = costs[j-1] + (j-i) * (j-i);

            ans = min(ans, jcost + solveMemo(j, n, costs, dp));
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        // return solveRec(0, n, costs);
        
        vector<int> dp(n+1, -1);
        return solveMemo(0, n, costs, dp);
    }
};