class Solution {
public:
    // Plain Reccursion 
    int robHelper(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;

        int include = nums[i] + robHelper(nums,i+2);
        int exclude = robHelper(nums,i+1);

        return max(include,exclude);
    }

    // DP : Memoization
    int solveMemo(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int include = nums[i] + solveMemo(nums,i+2, dp);
        int exclude = solveMemo(nums, i+1, dp);

        dp[i] = max(include,exclude);
        return dp[i];
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solveMemo(nums, 0, dp);
    }
};