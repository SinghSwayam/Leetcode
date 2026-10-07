class DisjointSet{

public: 
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        DisjointSet ds(n);
        for(auto c : connections){
            if(ds.findUltParent(c[0]) != ds.findUltParent(c[1])){
                ds.unionBySize(c[0], c[1]);
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(ds.findUltParent(i) == i){
                count++;
            }
        }
        return count-1;
    }
};