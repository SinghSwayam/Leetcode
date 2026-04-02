class Solution {
public:
    void solve(vector<string>& ans,int open,int close,string& currAns){
        if(open ==0 && close==0){
            ans.push_back(currAns);
            return;
        }

        if(open > 0){
            currAns.push_back('(');
            solve(ans,open-1,close,currAns);
            currAns.pop_back();
        }

        if(close > open){
            currAns.push_back(')');
            solve(ans,open,close-1,currAns);
            currAns.pop_back();
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=n;
        int close=n;
        string currAns="";

        solve(ans,open,close,currAns);

        return ans;
    }
};