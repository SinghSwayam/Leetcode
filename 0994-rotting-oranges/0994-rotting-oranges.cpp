class Solution {
public:
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue< pair< pair<int, int>, int> > q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int time = 0;

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int r = front.first.first;
            int c = front.first.second;
            int t = front.second;
            time = max(time, t);
            for(int i=0; i<4; i++){
                int nrow = r + delr[i];
                int ncol = c + delc[i];

                if(nrow >= 0 && nrow < n 
                && ncol >= 0 && ncol < m 
                && !vis[nrow][ncol] 
                && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t + 1});
                    grid[nrow][ncol] = 2;
                    vis[nrow][ncol] = 1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return time;
    }
};