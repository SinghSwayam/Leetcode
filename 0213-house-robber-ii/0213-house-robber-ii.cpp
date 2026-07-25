class Solution {
public:
    int robHelper(vector<int>& nums, int i, int end){
        if(i >= end) return 0;

        int include = nums[i] + robHelper(nums,i+2, end);
        int exclude = robHelper(nums,i+1, end);

        return max(include,exclude);
    }

    int solveMemo(vector<int>& nums, int i, int end, vector<int>& dp){
        if(i >= end) return 0;

        if(dp[i] != -1) return dp[i];

        int include = nums[i] + solveMemo(nums,i+2,end,dp);
        int exclude = solveMemo(nums, i+1,end,dp);

        dp[i] = max(include,exclude);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int s = nums.size();

        vector<int> dp(s, -1);
        int m1 = solveMemo(nums, 0, s-1, dp);

        fill(dp.begin(), dp.end(), -1);
        int m2 = solveMemo(nums, 1, s, dp);

        return max(m1, m2);
    }
};