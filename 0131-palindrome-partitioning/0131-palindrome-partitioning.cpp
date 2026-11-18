class Solution {
public:
    bool isPalindrome(string& s){
        int i=0;
        int j= s.size() - 1;

        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int idx, string& s, vector<string>& curr, vector<vector<string>>& ans){
        int n = s.size();

        if(idx == n){
            ans.push_back(curr);
            return;
        }

        for(int i=idx; i<n; i++){
            string currString = s.substr(idx, i-idx+1);
            if(isPalindrome(currString)){
                curr.push_back(currString);
                solve(i+1, s, curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        
        solve(0, s, curr, ans);
        return ans;
    }
};