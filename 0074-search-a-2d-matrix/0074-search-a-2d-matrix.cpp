class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int s = 0;
        int e = (rows * cols) - 1;
    

    while(s <= e){
        int mid = s + (e - s) / 2;

        int r = mid / cols;
        int c = mid % cols;

        if(target == matrix[r][c]){
            return true;
        }else if(target < matrix[r][c]){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }

    return false;
    }
};