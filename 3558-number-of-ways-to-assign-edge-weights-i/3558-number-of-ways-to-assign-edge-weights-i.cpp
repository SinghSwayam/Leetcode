class Solution {
public:
    int M = 1e9+7;

    using ll = long long;

    ll power(ll num, ll pow) {
        ll ans = 1;

        while (pow > 0) {
            if (pow & 1)
                ans = (ans * num) % M;

            num = (num * num) % M;
            pow >>= 1;
        }

        return ans;
    }

    int getMaxDepth(unordered_map<int,vector<int>>& adj,int node, int parent){
        int depth = 0;

        for(int& ngbr : adj[node]){
            if(ngbr == parent) continue;

            depth = max(depth,getMaxDepth(adj, ngbr, node) + 1);
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d = getMaxDepth(adj, 1, -1);

        return power(2, d-1);
    }
};