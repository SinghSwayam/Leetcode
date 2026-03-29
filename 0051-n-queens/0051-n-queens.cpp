class Solution {
public:
    void storeSol(vector<vector<char>>& board,int n,vector<vector<string>>& ans){
        vector<string> output;
        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=0;j<n;j++){
                temp.push_back(board[i][j]);
            }
            output.push_back(temp);
        }
        ans.push_back(output);
    }

    bool isSafe(int row,int col,vector<vector<char>>& board,int n){
        int i=row;
        int j=col;
        while(j>=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            j--;
        }

        i=row;
        j=col;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }

        i=row;
        j=col;
        while(i<n && j>=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
        }

        return true;

    }

    void solve(vector<vector<char>>& board,int col,int n,vector<vector<string>>& ans){
        if(col >= n){
            storeSol(board,n,ans);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(board,col+1,n,ans);
                board[row][col] = '.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        int col=0;
        solve(board,col,n,ans);
        return ans;
    }
};