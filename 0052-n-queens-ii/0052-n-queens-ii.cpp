class Solution {
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> upperLeftDiagonalCheck;
    unordered_map<int,bool> bottomLeftDiagonalCheck;
public:
    bool isSafe(int row,int col,int n){
        if(rowCheck[row] == true) return false;
        if(upperLeftDiagonalCheck[n-1+col-row] == true) return false;
        if(bottomLeftDiagonalCheck[row+col] == true) return false;

        return true;

    }

    void solve(vector<vector<char>>& board,int col,int n,int& ans){
        if(col >= n){
            ++ans;
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,n)){
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagonalCheck[n-1+col-row] = true;
                bottomLeftDiagonalCheck[row+col] = true;
                solve(board,col+1,n,ans);
                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagonalCheck[n-1+col-row] = false;
                bottomLeftDiagonalCheck[row+col] = false;
            }
        }

    }

    int totalNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        int ans=0;
        int col=0;
        solve(board,col,n,ans);
        return ans;
        return ans;
    }
};