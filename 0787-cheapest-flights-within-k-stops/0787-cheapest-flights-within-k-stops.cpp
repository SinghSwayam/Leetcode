class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto f : flights) { 
            adj[f[0]].push_back({f[1], f[2]}); 
        }

        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});
        // steps, node, distance
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            auto [node, cost] = it.second;
            
            if(stops > k) continue;
            
            for(auto [ngbrNode, ngbrDist] : adj[node]){
                if(cost + ngbrDist < dist[ngbrNode]){
                    dist[ngbrNode] = cost + ngbrDist;
                    q.push({stops+1, {ngbrNode, dist[ngbrNode]}});
                }
            }
        }
        
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};