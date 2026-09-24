class Solution {
public:
    vector<vector<int>>dir = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        queue<pair<pair<int, int>, int> > q;
        q.push({{0,0}, 1});
        grid[0][0] = 1;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            auto [x, y] = node.first;
            int d = node.second;

            if(x == n-1 && y==n-1){
                return d;
            }

            for(int i=0; i<8; i++){
                int newx = dir[i][0] + x;
                int newy = dir[i][1] + y;

                if(newx >= 0 && newx < n && newy >= 0 && newy < n && grid[newx][newy] != 1){
                    q.push({{newx, newy}, d+1});
                    grid[newx][newy] = 1;
                }
            }
        }
        return -1;
    }
};