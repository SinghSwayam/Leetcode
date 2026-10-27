class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while(!q.empty()){
            int idx = q.front();
            q.pop();
            

            if(arr[idx] == 0){
                return true;
            }

            int ljump = idx - arr[idx];
            if(ljump >= 0 && !vis[ljump]){
                q.push(ljump);
                vis[ljump] = 1;
            }

            int rjump = idx + arr[idx];
            if(rjump < n && !vis[rjump]){
                q.push(rjump);
                vis[rjump] = 1;
            }
        }
        return false;
    }
};