class Solution {
public:
    bool dfs(int i, vector<vector<int>> &adj, vector<int>& vis, vector<int>& pathVis){
        vis[i] = 1;
        pathVis[i] = 1;
        
        for(auto it : adj[i]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis)){
                    return true;
                }
            }else if(pathVis[it]){
                return true;
            }
            
        }
        pathVis[i] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[u].push_back(v);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)) return false;
            }
        }
        return true;
    }
};