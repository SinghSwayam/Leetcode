class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int i, int j, int m, int n, vector<vector<int>>& vis, vector<vector<int>>& grid){
        stack<pair<int, int>> st;
        st.push({i, j});

        vis[i][j] = 1;

        while(!st.empty()){
            auto [r, c] = st.top();
            st.pop();

            for(int d=0; d<4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1){
                    vis[nr][nc] = 1;
                    st.push({nr, nc});
                }
            }
        }
    }

    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    cnt++;
                    dfs(i, j, m, n, vis, grid);
                }
            }
        }

        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(countIslands(grid) != 1){
            return 0;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;

                    if (countIslands(grid) != 1) return 1;

                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};