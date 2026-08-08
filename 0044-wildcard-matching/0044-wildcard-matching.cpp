class Solution {
public:
    bool solveRec(string& s, int si, string& p, int pi) {
        if(si == s.size() && pi == p.size()) return true;

        if(si == s.size() && pi < p.size()){
            while(pi < p.size()){
                if(p[pi++] != '*') return false;
            }
            return true;
        }

        if(s[si] == p[pi] || p[pi] == '?'){
            return solveRec(s,si+1,p,pi+1);
        }

        if(p[pi] == '*'){
            // * -> empty
            bool caseA = solveRec(s,si,p,pi+1);
            // * -> matches with a character
            bool caseB = solveRec(s,si+1,p,pi);

            return caseA || caseB;
        }

        return false;
        
    }

    bool solveMemo(string& s, int si, string& p, int pi, vector<vector<int>>& dp) {
        if(si == s.size() && pi == p.size()) return true;

        if(si == s.size() && pi < p.size()){
            while(pi < p.size()){
                if(p[pi++] != '*') return false;
            }
            return true;
        }

        if(dp[si][pi] != -1) return dp[si][pi];

        if(s[si] == p[pi] || p[pi] == '?'){
            return dp[si][pi] = solveMemo(s,si+1,p,pi+1,dp);
        }

        if(p[pi] == '*'){
            // * -> empty
            bool caseA = solveMemo(s,si,p,pi+1,dp);
            // * -> matches with a character
            bool caseB = solveMemo(s,si+1,p,pi,dp);

            return dp[si][pi] = (caseA || caseB);
        }

        return false;
        
    }

    bool isMatch(string s, string p) {
        // return solveRec(s,0,p,0);

        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solveMemo(s, 0, p, 0, dp);
    }
};