class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto f : flights) { 
            adj[f[0]].push_back({f[1], f[2]}); 
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int stops = 0; stops <= k; stops++) {
            vector<int> temp = dist;

            for (int u = 0; u < n; u++) {
                if (dist[u] == INT_MAX) continue;
                
                for (auto [v, price] : adj[u]) { 
                    temp[v] = min(temp[v], dist[u] + price); 
                }
            }

            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};