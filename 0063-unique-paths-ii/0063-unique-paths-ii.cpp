class Solution {
public:
    int solveRecursion(vector<vector<int>>& obstacleGrid, int i, int j){
        if(i >= obstacleGrid.size() || j >= obstacleGrid[0].size()) return 0;
        
        if(obstacleGrid[i][j] == 1) return 0;
        
        if(i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) return 1;

        int ans = solveRecursion(obstacleGrid, i+1, j) + solveRecursion(obstacleGrid, i, j+1);
        return ans;
    }

    int solveMemoization(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp){
        if(i >= obstacleGrid.size() || j >= obstacleGrid[0].size()) return 0;
            
        if(obstacleGrid[i][j] == 1) return 0;
                
        if(i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) return 1;

        if(dp[i][j] != -1) return dp[i][j]; 

        int ans = solveMemoization(obstacleGrid, i+1, j, dp) + solveMemoization(obstacleGrid, i, j+1, dp);
        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // int ans = solveRecursion(obstacleGrid, 0, 0);
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int ans = solveMemoization(obstacleGrid, 0, 0, dp);
        return ans;
    }
};