class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            queue<int> q;

            if(color[i] != -1) continue;

            q.push(i);
            color[i] = 0;
            
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                
                for(int it : graph[frontNode]){
                    if(color[it] == -1){
                        color[it] = !color[frontNode];
                        q.push(it);
                    }else{
                        if(color[it] == color[frontNode]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};