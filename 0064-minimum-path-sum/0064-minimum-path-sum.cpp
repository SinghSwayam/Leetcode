class Solution {
public:
    int solveRecursion(vector<vector<int>>& grid, int i, int j){
        if(i >= grid.size() || j >= grid[0].size()){
            return INT_MAX;
        }

        if(i == grid.size()-1 &&  j == grid[0].size()-1){
            return grid[i][j];
        }

        int downAns = solveRecursion(grid, i+1, j);
        int rightAns = solveRecursion(grid, i, j+1);

        int ans = grid[i][j] + min(downAns, rightAns);
        return ans;
    }

    int solveMemoization(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i >= grid.size() || j >= grid[0].size()){
            return INT_MAX;
        }

        if(i == grid.size()-1 &&  j == grid[0].size()-1){
            return grid[i][j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        int downAns = solveMemoization(grid, i+1, j, dp);
        int rightAns = solveMemoization(grid, i, j+1, dp);

        int ans = grid[i][j] + min(downAns, rightAns);
        return dp[i][j] = ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        // int ans = solveRecursion(grid, 0, 0);

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int ans = solveMemoization(grid, 0, 0, dp);

        return ans;
    }
};