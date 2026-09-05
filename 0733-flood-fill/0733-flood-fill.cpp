class Solution {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    void bfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& visited, int n, int m){
        int originalColor = image[sr][sc];
        visited[sr][sc] = 1;
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && image[nrow][ncol] == originalColor){
                    visited[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }            
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        bfs(image, sr, sc, color, visited, n, m);
        return image;
    }
};