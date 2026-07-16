class Solution {
public:
    int solveReccursion(string& a, string& b, int i, int j){
        if(i >= a.length()) return 0;

        if(j >= b.length()) return 0;

        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solveReccursion(a, b, i+1, j+1);
        }else{
            ans = max(solveReccursion(a, b, i, j+1), solveReccursion(a, b, i+1, j));
        }
        return ans;
    }

    int solveMemoization(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        if(i >= a.length()) return 0;

        if(j >= b.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solveMemoization(a, b, i+1, j+1, dp);
        }else{
            ans = max(solveMemoization(a, b, i, j+1, dp), solveMemoization(a, b, i+1, j, dp));
        }
        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        // return solveReccursion(text1, text2, 0, 0);

        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        return solveMemoization(text1, text2, 0, 0, dp);
    }
};