class Solution {
public:
    int solveRec(vector<vector<int>>& pairs, int prev, int curr){
        if(curr >= pairs.size()) return 0;

        int inc = 0;
        if(prev == -1 || pairs[prev][1] < pairs[curr][0]){
            inc = 1 + solveRec(pairs, curr, curr+1);
        }
        int exc = solveRec(pairs, prev, curr+1);

        return max(inc, exc);
    }

    int solveMemo(vector<vector<int>>& pairs, int prev, int curr, vector<vector<int>>& dp){
        if(curr >= pairs.size()) return 0;

        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];

        int inc = 0;
        if(prev == -1 || pairs[prev][1] < pairs[curr][0]){
            inc = 1 + solveRec(pairs, curr, curr+1);
        }
        int exc = solveRec(pairs, prev, curr+1);

        return dp[prev+1][curr] = max(inc, exc);
    }

    int solveTab(vector<vector<int>>& pairs){
        int n = pairs.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                int inc = 0;
                if(prev == -1 || pairs[prev][1] < pairs[curr][0]){
                    inc = 1 + dp[curr+1][curr+1];
                }
                int exc = dp[prev+1][curr+1];

                dp[prev+1][curr] = max(inc, exc);
            }
        }
        return dp[0][0];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n == 1) return 1;
        sort(pairs.begin(), pairs.end());

        // return solveRec(pairs, -1, 0);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMemo(pairs, -1, 0, dp);
        return solveTab(pairs);
    }
};