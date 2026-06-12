class Solution {
    int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    void dfs(int node, int parent, int d, vector<vector<int>>& adj,vector<vector<int>>& ancestor, vector<int>& depth, int cols){
        ancestor[node][0] = parent;
        depth[node] = d;

        for(int j=1;j<cols;j++){
            if(ancestor[node][j-1] != -1){
                ancestor[node][j] = ancestor[ ancestor[node][j-1] ][j-1];
            }else{
                ancestor[node][j] = -1;
            }
        }

        for(int ngbr : adj[node]){
            if(ngbr != parent){
                dfs(ngbr, node, d + 1, adj, ancestor, depth, cols);
            }
        }
    }

    int getLCA(int u, int v, vector<vector<int>>& ancestor, vector<int>& depth, int cols){
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < cols; j++) {
            if ((diff >> j) & 1) { 
                u = ancestor[u][j];
            }
        }

        if (u == v) return u;

        for (int j = cols - 1; j >= 0; j--) {
            if (ancestor[u][j] != -1 && ancestor[u][j] != ancestor[v][j]) {
                u = ancestor[u][j];
                v = ancestor[v][j];
            }
        }
        return ancestor[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cols = log2(n) +1;

        vector<vector<int>> ancestor(n + 1, vector<int>(cols, -1));
        vector<int> depth(n + 1, 0);

        dfs(1, -1, 0, adj, ancestor, depth, cols);

        vector<int> ans;
        for(auto& query : queries){
            int u = query[0];
            int v = query[1];

            if(u == v) {
                ans.push_back(0);
                continue;
            }

            int lca = getLCA(u, v, ancestor, depth, cols);
            int d = depth[u] + depth[v] - 2 * depth[lca]; 

            ans.push_back(power(2, d - 1));
        }
        return ans;
    }
};