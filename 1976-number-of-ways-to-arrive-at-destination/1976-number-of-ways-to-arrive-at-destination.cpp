class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9+7;
        vector< vector< pair<int,int> > > adj(n);
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int c = it[2];

            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        priority_queue< pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq;
        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [currDist, currNode] = pq.top();
            pq.pop();

            for(auto [ngbrNode, ngbrDist] : adj[currNode]){
                if(ngbrDist + currDist < dist[ngbrNode]){
                    dist[ngbrNode] = ngbrDist + currDist;
                    pq.push({dist[ngbrNode], ngbrNode});
                    ways[ngbrNode] = ways[currNode];
                }else if(ngbrDist + currDist == dist[ngbrNode]){
                    ways[ngbrNode] = (ways[ngbrNode] + ways[currNode]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};