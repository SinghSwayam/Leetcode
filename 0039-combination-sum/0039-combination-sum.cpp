class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& currAns,int start){
        if(target == 0){
            ans.push_back(currAns);
            return;
        }

        if(target<0){
            return;
        }

        for(int i=start;i<candidates.size();i++){
            currAns.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,currAns,i);
            currAns.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currAns;

        solve(candidates,target,ans,currAns,0);
        return ans;
    }
};