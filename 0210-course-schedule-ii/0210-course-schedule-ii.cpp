class Solution {
public:
    bool dfs(int i, vector<vector<int>> &adj, vector<int>& vis, vector<int>& pathVis, vector<int>& ans){
        vis[i] = 1;
        pathVis[i] = 1;
        
        for(auto it : adj[i]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis, ans)){
                    return true;
                }
            }else if(pathVis[it]){
                return true;
            }
            
        }
        pathVis[i] = 0;
        ans.push_back(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& p : prerequisites){
            int u = p[0];
            int v = p[1];
            
            adj[u].push_back(v);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis, ans)) return {};
            }
        }
        return ans;
    }
};