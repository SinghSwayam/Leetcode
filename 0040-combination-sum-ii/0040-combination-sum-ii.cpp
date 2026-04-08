class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& currAns,int start){
        if(target == 0){
            ans.push_back(currAns);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(candidates[i] > target) return;

            if(i>start && candidates[i]==candidates[i-1]) continue;

            currAns.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,currAns,i+1);
            currAns.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> currAns;

        solve(candidates,target,ans,currAns,0);
        return ans;
    }
};