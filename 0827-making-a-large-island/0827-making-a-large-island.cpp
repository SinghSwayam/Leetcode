class DisjointSet{
private:

public: 
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionSize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
    bool isValid(int nr, int nc, int n){
        return (nr >= 0 && nr < n && nc >= 0 && nc < n);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        DisjointSet ds(n*n);
        // Step 1: Connecting componenets
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0) continue;
                
                int currNode = (row * n) + col;
                
                for(int i=0; i<4; i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    
                    if(isValid(nr, nc, n) && grid[nr][nc] == 1){
                        int adjNode = (nr * n) + nc;
                        ds.unionSize(currNode, adjNode);
                    }
                }
            }
        }
        
        // Step 2: Try to convert every 0 to 1
        int maxi = INT_MIN;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1) continue;
                
                int currNode = (row * n) + col;
                set<int> components;
                for(int i=0; i<4; i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    
                    if(isValid(nr, nc, n) && grid[nr][nc] == 1){
                        int adjNode = (nr * n) + nc;
                        components.insert(ds.findParent(adjNode));
                    }
                }
                
                int totalSize = 0;
                for(auto it : components){
                    totalSize += ds.size[it]; 
                }
                
                maxi = max(maxi, totalSize + 1);
            }
        }

        for(int i=0; i<n*n; i++){
            int p = ds.findParent(i);
            maxi = max(maxi, ds.size[p]);
        }
        return maxi;
    }
};