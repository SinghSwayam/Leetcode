class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({grid[0][0], {0,0}});
        visited[0][0] = 1;
        int maxi = grid[0][0];

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            auto [r,c] = it.second;

            maxi = max(maxi, dist);

            if(r == n-1 && c == n-1){
                return maxi;
            }

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]){
                    pq.push({grid[nr][nc], {nr, nc}});
                    visited[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};