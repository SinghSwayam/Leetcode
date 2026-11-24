class Solution {
public:
    void dfs(int curr, int n, vector<int>& ans){
        if(curr > n) return;

        ans.push_back(curr);

        for(int i=0; i<=9; i++){
            int next = curr*10 + i;

            if(next > n) break;

            dfs(next, n, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        for(int i=1; i<=9; i++){
            dfs(i, n, ans);
        }

        return ans;
    }
};