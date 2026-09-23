class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> prob(n, 0.0);
        priority_queue<pair<double, int>> pq; // max heap

        prob[start_node] = 1.0;
        pq.push({1.0, start_node});

        while(!pq.empty()){
            auto [currProb, node] = pq.top();
            pq.pop();

            for(auto [ngbr, ngbrProb] : adj[node]){
                double newProb = currProb * ngbrProb;
                if(newProb > prob[ngbr]){
                    prob[ngbr] = newProb;
                    pq.push({newProb, ngbr});
                }
            }
        }
        return prob[end_node];
    }
};