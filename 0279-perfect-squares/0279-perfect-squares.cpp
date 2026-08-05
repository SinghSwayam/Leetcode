class Solution {
public:
    int numSqrHelper(int n){
        if(n == 0) return 0;

        int i=1;
        int end=sqrt(n);
        int ans = INT_MAX;

        while(i<=end){
            int perfectSqr = i*i;
            int numOfPerfectSqrs = 1 + numSqrHelper(n-perfectSqr);
            if(numOfPerfectSqrs < ans) {
                ans = numOfPerfectSqrs;
            }
            ++i;
        }

        return ans;

    }

    int solveMemo(int n, vector<int>& dp){
        if(n == 0) return 0;

        if(dp[n] != -1) return dp[n];

        int i=1;
        int end=sqrt(n);
        int ans = INT_MAX;

        while(i<=end){
            int perfectSqr = i*i;
            int numOfPerfectSqrs = 1 + solveMemo(n-perfectSqr, dp);
            if(numOfPerfectSqrs < ans) {
                ans = numOfPerfectSqrs;
            }
            ++i;
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        // return numSqrHelper(n);

        vector<int> dp(n+1, -1);
        return solveMemo(n, dp);
    }
};