class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, cost});
                adj[j].push_back({i, cost});
            }
        }

        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        vector<int> visited(n, 0);
        pq.push({0, 0});

        int ans = 0;
        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();

            if(visited[node]) continue;

            visited[node] = 1;
            ans += wt;

            for(auto [ngbr, cost] : adj[node]) {
                if(!visited[ngbr]) {
                    pq.push({cost, ngbr});
                }
            }
        }
        return ans;
    }
};