class Solution {
public:
    int solveRecursion(vector<int>& piles, int s, int e){
        if(s == e) return piles[s];

        int left = piles[s] - solveRecursion(piles, s+1, e);
        int right = piles[e] - solveRecursion(piles, s, e-1);

        return max(left, right);
    }

    int solveMemoization(vector<int>& piles, int s, int e, vector<vector<int>>& dp){
        if(s == e) return piles[s];

        if(dp[s][e] != -1) return dp[s][e];

        int left = piles[s] - solveMemoization(piles, s+1, e, dp);
        int right = piles[e] - solveMemoization(piles, s, e-1, dp);

        return dp[s][e] = max(left, right);
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // int ans = solveRecursion(piles, 0, n-1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solveMemoization(piles, 0, n-1, dp);
        return ans > 0;
    }
};