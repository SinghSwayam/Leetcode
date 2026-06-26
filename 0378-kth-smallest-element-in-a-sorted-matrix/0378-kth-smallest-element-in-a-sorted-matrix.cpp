class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        priority_queue<int> q;
        for(int i=0; i<rows; i++){
            for(int j=0;j<cols;j++){
                if(q.size() != k){
                    q.push(matrix[i][j]);
                }else{
                    if(matrix[i][j] < q.top()){
                        q.pop();
                        q.push(matrix[i][j]);
                    }
                }
            }
        }
        return q.top();
    }
};