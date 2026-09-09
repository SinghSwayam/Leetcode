class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for(int j=0; j<m; j++){
            if(!visited[0][j] && grid[0][j] == 1){
                q.push({0, j});
                visited[0][j] = 1;
            }
            if(!visited[n-1][j] && grid[n-1][j] == 1){
                q.push({n-1, j});
                visited[n-1][j] = 1;
            }
        }

        for(int i=0; i<n; i++){
            if(!visited[i][0] && grid[i][0]){
                q.push({i, 0});
                visited[i][0] = 1;
            }
            if(!visited[i][m-1] && grid[i][m-1]){
                q.push({i, m-1});
                visited[i][m-1] = 1;
            }
        }

        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            int r = frontNode.first;
            int c = frontNode.second;

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n
                && nc >= 0 && nc < m
                && !visited[nr][nc] && grid[nr][nc] == 1
                ){
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    ++count;
                }
            }
        }
        return count;
    }
};