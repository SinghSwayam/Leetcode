class Solution {
public:
    int solveRecursion(vector<vector<int>>& triangle, int row, int col){
        if(row == triangle.size()-1){
            return triangle[row][col];
        }

        int down = triangle[row][col] + solveRecursion(triangle, row+1, col);
        int downRight = triangle[row][col] + solveRecursion(triangle, row+1, col+1);

        return min(down, downRight);
    }

    int solveMemoization(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp){
        if(row == triangle.size()-1){
            return triangle[row][col];
        }

        if(dp[row][col] != -1) return dp[row][col];

        int down = triangle[row][col] + solveMemoization(triangle, row+1, col, dp);
        int downRight = triangle[row][col] + solveMemoization(triangle, row+1, col+1, dp);

        return dp[row][col] = min(down, downRight);
    }

    int solveTabulation(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int row=n-2; row>=0; row--){
            for(int col=0; col<=row; col++){
                dp[row][col] = triangle[row][col] + min(dp[row+1][col], dp[row+1][col+1]);
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        // int ans = solveRecursion(triangle, 0, 0);

        // int n = triangle.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solveMemoization(triangle, 0, 0, dp);

        int ans = solveTabulation(triangle);
        return ans;
    }
};