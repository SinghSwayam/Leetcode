class Solution {
public:
    int offset = 1000;
    int solve(vector<int>& nums,int idx, int sum, int target,vector<vector<int>>& dp){
        if(idx == nums.size()){
            return sum == target;
        }

        if(dp[idx][sum+offset] != -1){
            return dp[idx][sum+offset];
        }

        int add = solve(nums, idx + 1, sum + nums[idx], target, dp);
        int sub = solve(nums, idx + 1, sum - nums[idx], target, dp);
        
        return dp[idx][sum+offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return solve(nums, 0, 0, target, dp);
    }
};