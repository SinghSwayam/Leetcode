class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        
        queue<pair< pair<int, int>, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({ {i,j}, 0 });
                    visited[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            
            int r = frontNode.first.first;
            int c = frontNode.first.second;
            int step = frontNode.second;
            
            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                
                if(nr >= 0 && nr < n && 
                nc >= 0 && nc < m &&
                !visited[nr][nc]
                ){
                    q.push({{nr, nc}, step+1});
                    visited[nr][nc] = 1;
                    distance[nr][nc] = step + 1;
                }
            }
        }
        return distance;
    }
};