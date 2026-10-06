class DisjointSet{
public: 
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUltParent(int node){
        if(node == parent[node])
            return node;
        
        return parent[node] = findUltParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);

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
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }
        return cnt;
    }
};