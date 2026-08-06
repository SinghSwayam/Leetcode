class Solution {
public:
    int solveRec(vector<int>& arr, map<pair<int,int>, int>& maxi,int s, int e){
        if(s >= e) return 0;

        int minSum = INT_MAX;
        for(int i=s; i<e; i++){
            int curr = (maxi[{s, i}] * maxi[{i+1, e}]) + 
                        solveRec(arr, maxi, s, i) + 
                        solveRec(arr, maxi, i+1, e);
            
            minSum = min(minSum, curr);
        }
        return minSum;
    }

    int solveMemo(vector<int>& arr, map<pair<int,int>, int>& maxi,int s, int e, vector<vector<int>>& dp){
        if(s >= e) return 0;

        if(dp[s][e] != -1) return dp[s][e];

        int minSum = INT_MAX;
        for(int i=s; i<e; i++){
            int curr = (maxi[{s, i}] * maxi[{i+1, e}]) + 
                        solveMemo(arr, maxi, s, i, dp) + 
                        solveMemo(arr, maxi, i+1, e, dp);
            
            minSum = min(minSum, curr);
        }
        return dp[s][e] = minSum;
    }

    int solveTab(vector<int>& arr, map<pair<int,int>, int>& maxi){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int s=n-1; s>=0; s--){
            for(int e=0; e<=n-1; e++){
                if(s >= e){
                    continue;
                }

                int minSum = INT_MAX;
                for(int i=s; i<e; i++){
                    int curr = (maxi[{s, i}] * maxi[{i+1, e}]) + dp[s][i] + dp[i+1][e];
                    minSum = min(minSum, curr);
                }
                dp[s][e] = minSum;
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int,int>, int> maxi;
        for(int i=0; i<n; i++){
            maxi[{i,i}] = arr[i];

            for(int j=i+1; j<n; j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }

        int s = 0;
        int e = n-1;
        // int ans = solveRec(arr, maxi, s, e);

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // int ans = solveMemo(arr, maxi, s, e, dp);

        int ans = solveTab(arr, maxi);

        return ans;
    }
};