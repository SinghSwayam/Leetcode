class Solution {
public:
    void findAllSubsets(vector<int>& nums, vector<vector<int>>& ans,vector<int>& currAns, int i){
        ans.push_back(currAns);
        
        for(int j=i;j<nums.size();j++){
            if(j > i && nums[j] == nums[j-1]) continue;

            currAns.push_back(nums[j]);
            findAllSubsets(nums,ans,currAns,j+1);
            currAns.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> currAns;
        findAllSubsets(nums,ans,currAns,0);
        
        return ans;
    }
};