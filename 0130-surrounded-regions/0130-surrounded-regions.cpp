class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    
    void dfs(vector<vector<char>>& board, int r, int c, vector<vector<int>>& visited, int n, int m){
        visited[r][c] = 1;
        
        for(int i=0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            
            if(nr >= 0 && nr < n-1 && nc >= 0 && nc < m-1 && 
                !visited[nr][nc] && board[nr][nc] == 'O'){
                dfs(board, nr, nc, visited, n, m);
            }
        }
    }
  
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        // traverse rows
        for(int j=0; j<m; j++){
            if(!visited[0][j] && board[0][j] == 'O'){
                dfs(board, 0, j, visited, n, m);
            }
            
            if(!visited[n-1][j] && board[n-1][j] == 'O'){
                dfs(board, n-1, j, visited, n, m);
            }
        }
        // traverse cols
        for(int i=0; i<n; i++){
            if(!visited[i][0]  && board[i][0] == 'O'){
                dfs(board, i, 0, visited, n, m);
            }
            
            if(!visited[i][m-1]  && board[i][m-1] == 'O'){
                dfs(board, i, m-1, visited, n, m);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};