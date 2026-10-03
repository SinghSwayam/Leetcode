class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto e : times){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
        }

        priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
        vector<int> dist(n+1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [w, node] = pq.top();
            pq.pop();

            for(auto [ngbr, d] : adj[node]){
                if(d + w < dist[ngbr]){
                    dist[ngbr] = d+w;
                    pq.push({d+w, ngbr});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};