class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int total = rows*cols;
        int count =0;
        vector<int> ans;

        int startRow = 0;
        int endCol = cols-1;
        int endRow = rows-1;
        int startCol = 0;

        while(count < total){

            for(int i=startCol;i<=endCol && count < total ;i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            for(int i=startRow;i<=endRow && count < total;i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for(int i=endCol;i>=startCol && count < total ;i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            for(int i=endRow;i>=startRow && count < total;i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;

        }

        return ans;

    }
};