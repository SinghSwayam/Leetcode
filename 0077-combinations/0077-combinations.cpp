class Solution {
public:
    void findCombination(vector<vector<int>>& ans,vector<int>& currAns,int start,int n,int k){
        if(currAns.size() == k){
            ans.push_back(currAns);
            return;
        }

        for(int i=start;i<=n;i++){
            currAns.push_back(i);
            findCombination(ans,currAns,i+1,n,k);
            currAns.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> currAns;
        findCombination(ans,currAns,1,n,k);
        return ans;
    }
};