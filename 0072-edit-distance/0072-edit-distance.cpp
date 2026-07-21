class Solution {
public:
    int solveRecursion(string& word1, string& word2, int i, int j){
        // base case
        if(i >= word1.length()){
            // word1 has ended
            // it means that that word1 length is smaller than word2
            return word2.length() - j;
        }
        if(j >= word2.length()){
            // word2 has ended
            // it means that that word2 length is smaller than word1
            return word1.length() - i;
        }

        int ans = 0;
        if(word1[i] == word2[j]){
            // matching
            ans = solveRecursion(word1, word2, i+1, j+1);
        }else{
            // not matching
            // insertion operation
            int op1 = 1 + solveRecursion(word1, word2, i, j+1);
            // removal operation
            int op2 = 1 + solveRecursion(word1, word2, i+1, j);
            // replace operation
            int op3 = 1 + solveRecursion(word1, word2, i+1, j+1);
            ans = min({op1, op2, op3});
        }

        return ans;
    }

    int solveMemoization(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        // base case
        if(i >= word1.length()){
            // word1 has ended
            // it means that that word1 length is smaller than word2
            return word2.length() - j;
        }
        if(j >= word2.length()){
            // word2 has ended
            // it means that that word2 length is smaller than word1
            return word1.length() - i;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(word1[i] == word2[j]){
            // matching
            dp[i][j] = solveMemoization(word1, word2, i+1, j+1, dp);
        }else{
            // not matching
            // insertion operation
            int op1 = 1 + solveMemoization(word1, word2, i, j+1, dp);
            // removal operation
            int op2 = 1 + solveMemoization(word1, word2, i+1, j, dp);
            // replace operation
            int op3 = 1 + solveMemoization(word1, word2, i+1, j+1, dp);
            dp[i][j] = min({op1, op2, op3});
        }

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        // int ans = solveRecursion(word1, word2, 0, 0);

        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        int ans = solveMemoization(word1, word2, 0, 0, dp);
        return ans;
    }
};