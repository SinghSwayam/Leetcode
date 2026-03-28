class Solution {
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,-1,1,0};

public:
    bool isSafe(int x, int y, int rows, int cols, vector<vector<char>>& board, vector<vector<bool>>& visited){
        return ( (x>=0 && x<rows) && (y>=0 && y<cols) && (visited[x][y] == false) );
    }

    bool findWord(vector<vector<char>>& board,string& word,int x,int y,vector<vector<bool>>& visited,int rows,int cols,int i){
        if(board[x][y] != word[i]) return false;
        if(i == word.size()-1) return true;

        visited[x][y] = true;
        for(int k=0;k<4;k++){
            int newx = x + dx[k];
            int newy = y + dy[k];

            if(isSafe(newx, newy, rows, cols, board, visited)){
                if(findWord(board,word,newx,newy,visited,rows,cols,i+1))
                    return true;
            }
        }
        visited[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> visited(row,vector<bool>(col,false));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == word[0]){
                    if(findWord(board,word,i,j,visited,row,col,0))
                        return true;
                }
            }
        }

        return false;
    }
};