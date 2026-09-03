class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited){
        visited[node] = true;
        for(auto ngbr : adjList[node]){
            if(!visited[ngbr]){
                dfs(ngbr, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adjList(v);
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(i != j && isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<bool> visited(v, false);
        int count = 0;
        for(int i=0; i<v; i++){
            if(!visited[i]){
                count++;
                dfs(i, adjList, visited);
            }
        }
        return count;
    }
};