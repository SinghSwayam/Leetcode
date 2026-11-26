class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9;i++ ) {
            if (board[row][i] == num) {
                return false;
            }
            
            if (board[i][col] == num) {
                return false;
            }
            
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == num) {
                return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                char num = board[i][j];
                board[i][j] = '.';

                if (!isSafe(board, i, j, num)) {
                    return false;
                }
                board[i][j] = num;
            }
        }
        return true;
    }
};