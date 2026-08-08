class Solution {
public:
    bool solveRec(string& s1, string& s2, string& s3, int i, int j){
        int k = i+j;

        if(k == s3.size()) return true;

        if(i<s1.size() && s1[i]==s3[k]){
            int ans = solveRec(s1, s2, s3, i+1, j);
            if(ans == true){
                return true;
            }
        }

        if(j<s2.size() && s2[j]==s3[k]){
            int ans = solveRec(s1, s2, s3, i, j+1);
            if(ans == true){
                return true;
            }
        }

        return false;
    }

    bool solveMemo(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp){
        int k = i+j;

        if(k == s3.size()) return true;

        if(dp[i][j] != -1) return dp[i][j];

        bool match1 = false;
        bool match2 = false;
        if(i<s1.size() && s1[i]==s3[k]){
            match1 = solveMemo(s1, s2, s3, i+1, j, dp);
        }

        if(j<s2.size() && s2[j]==s3[k]){
            match2 = solveMemo(s1, s2, s3, i, j+1, dp);
        }

        return dp[i][j] = (match1 || match2);
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        // return solveRec(s1, s2, s3, 0, 0);

        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solveMemo(s1, s2, s3, 0, 0, dp);
    }
};