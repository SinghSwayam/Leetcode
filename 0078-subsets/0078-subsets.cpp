class Solution {
public:
    void findAllSubsets(vector<int>& nums, vector<vector<int>>& ans,vector<int>& currAns, int i){
        if(i == nums.size()){
            ans.push_back(currAns);
            return;
        }
        
        findAllSubsets(nums, ans, currAns,i+1);
        currAns.push_back(nums[i]);
        findAllSubsets(nums, ans, currAns,i+1);
        currAns.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> ans;
        // vector<int> currAns;
        // findAllSubsets(nums,ans,currAns,0);
        // return ans;

        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> ans;
        for(int num=0; num<subsets; num++){
            vector<int> temp;
            for(int i=0; i<n; i++){
                if(num & (1 << i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};