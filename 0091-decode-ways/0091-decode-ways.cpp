class Solution {
public:
    int solveRec(string& s, int i){
        if(i == s.size()) return 1;

        if(s[i] == '0') return 0;

        int ans = solveRec(s, i+1);

        if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6') ) ){
            ans += solveRec(s, i+2);
        }

        return ans;
    }

    int solveMemo(string& s, int i, vector<int>& dp){
        if(i == s.size()) return 1;

        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int ans = solveMemo(s, i+1, dp);

        if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6') ) ){
            ans += solveMemo(s, i+2, dp);
        }

        return dp[i] = ans;
    }

    int numDecodings(string s) {
        // return solveRec(s, 0);

        vector<int> dp(s.size()+1, -1);
        return solveMemo(s, 0, dp);
    }
};