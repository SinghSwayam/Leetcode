class Solution {
public:
    int solveRecursion(vector<vector<int>>& envelopes, int right, int left){
        if(right >= envelopes.size()) return 0;

        int inc = 0;
        if(left == -1 || (envelopes[right][0] > envelopes[left][0] && envelopes[right][1] > envelopes[left][1])){
            inc = 1 + solveRecursion(envelopes, right+1, right);
        }
        int exc = solveRecursion(envelopes, right+1, left);

        return max(inc, exc);
    }

    int solveMemoization(vector<vector<int>>& envelopes, int right, int left, vector<vector<int>>& dp){
        if(right >= envelopes.size()) return 0;

        if(dp[right][left+1] != -1) return dp[right][left+1];

        int inc = 0;
        if(left == -1 || (envelopes[right][0] > envelopes[left][0] && envelopes[right][1] > envelopes[left][1])){
            inc = 1 + solveMemoization(envelopes, right+1, right, dp);
        }
        int exc = solveMemoization(envelopes, right+1, left, dp);

        return dp[right][left+1] = max(inc, exc);
    }

    int solveTabulation(vector<vector<int>>& envelopes){
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int right = n-1; right >= 0; right--){
            for(int left = right-1; left >= -1; left--){
                int inc = 0;
                if(left == -1 || (envelopes[right][0] > envelopes[left][0] && envelopes[right][1] > envelopes[left][1])){
                    inc = 1 + dp[right+1][right+1];
                }
                int exc = dp[right+1][left+1];

                dp[right][left+1] = max(inc, exc);
            }
        }
        return dp[0][0];
    }

    int solveTabulationSpaceOptimized(vector<vector<int>>& envelopes){
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int right = n-1; right >= 0; right--){
            for(int left = right-1; left >= -1; left--){
                int inc = 0;
                if(left == -1 || (envelopes[right][0] > envelopes[left][0] && envelopes[right][1] > envelopes[left][1])){
                    inc = 1 + next[right+1];
                }
                int exc = next[left+1];
                curr[left+1] = max(inc, exc);
            }
            next = curr;
        }
        return next[0];
    }

    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int solveBinarySearch(vector<vector<int>>& envelopes){
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for(int i=1; i<envelopes.size(); i++){
            if(envelopes[i][1] > ans.back()){
                ans.push_back(envelopes[i][1]);
            }else{
                int h = envelopes[i][1];
                int idx = lower_bound(ans.begin(), ans.end(), h) - ans.begin();
                ans[idx] = envelopes[i][1];
            }
        }

        return ans.size();
    }    

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // sort(envelopes.begin(), envelopes.end());
        // int ans = solveRecursion(envelopes, 0,-1);
        
        // int n = envelopes.size();
        // sort(envelopes.begin(), envelopes.end());
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solveMemoization(envelopes, 0, -1, dp);

        // int ans = solveTabulation(envelopes);

        // int ans = solveTabulationSpaceOptimized(envelopes);

        int ans = solveBinarySearch(envelopes);
        
        return ans;
    }
};