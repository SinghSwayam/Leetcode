class Solution {
public:
    int solveRec(vector<vector<char>>& matrix, int i, int j, int row, int col, int& maxi){
        if(i >= row || j >= col){
            return 0;
        }

        // explore all 3 direction
        int right = solveRec(matrix, i, j+1, row, col, maxi);
        int diagonal = solveRec(matrix, i+1, j+1, row, col, maxi);
        int down = solveRec(matrix, i+1, j, row, col, maxi);

        // check can we build square from curr position
        if(matrix[i][j] == '0'){
            return 0;
        }

        int ans = 1 + min({right, diagonal, down});
        maxi = max(maxi, ans);
        return ans;
    }

    int solveMemo(vector<vector<char>>& matrix, int i, int j, int row, int col, int& maxi, vector<vector<int>>& dp){
        if(i >= row || j >= col){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // explore all 3 direction
        int right = solveMemo(matrix, i, j+1, row, col, maxi, dp);
        int diagonal = solveMemo(matrix, i+1, j+1, row, col, maxi, dp);
        int down = solveMemo(matrix, i+1, j, row, col, maxi, dp);

        // check can we build square from curr position
        if(matrix[i][j] == '0'){
            return 0;
        }

        int ans = 1 + min({right, diagonal, down});
        maxi = max(maxi, ans);
        return dp[i][j] = ans;
    }

    int solveTab(vector<vector<char>>& matrix, int row, int col, int& maxi){
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                // check can we build square from curr position
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                }else{
                    int ans = 1 + min({right, diagonal, down});
                    dp[i][j] = ans;
                    maxi = max(maxi, ans);
                }
           
            }
        }
        return dp[0][0];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int i=0;
        int j=0;
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        
        // solveRec(matrix, i, j, row, col, maxi); 

        // vector<vector<int>> dp(row+1, vector<int>(col+1, -1));
        // solveMemo(matrix, i, j, row, col, maxi, dp);

        solveTab(matrix, row, col, maxi);
        return maxi*maxi;
    }
};