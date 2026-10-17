class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int getCurrPath(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[r][c] != 0){
            return dp[r][c];
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int currPath = 1;
        
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                if(matrix[nr][nc] > matrix[r][c]){
                    currPath = max(currPath, 1 + getCurrPath(nr, nc, matrix, dp));
                }
            } 
        }
        return dp[r][c] = currPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxPath = 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                int currPath = getCurrPath(r, c, matrix, dp);
                maxPath = max(maxPath, currPath);
            }
        }
        return maxPath;
    }
};