class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> numRowOne(n);
        vector<int> numColOne(m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    numRowOne[i]++;
                    numColOne[j]++;
                }
            }
        }
        vector<vector<int>> diff(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                diff[i][j] = numRowOne[i] + numColOne[j] - (n-numRowOne[i]) - (m-numColOne[j]);
            }
        }
        return diff;
    }
};