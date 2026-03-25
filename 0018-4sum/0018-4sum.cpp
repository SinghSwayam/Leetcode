class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int numsSize = nums.size();

        for(int i=0;i < numsSize-3;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1;j<numsSize-2;j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;

                int l = j+1;
                int r = numsSize-1;

                while(l < r){
                    long long currAns = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(currAns == target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;

                        while(l<r && nums[l]==nums[l-1]) l++;
                        while(l<r && nums[r]==nums[r+1]) r--;
                    }else if(currAns<target){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};