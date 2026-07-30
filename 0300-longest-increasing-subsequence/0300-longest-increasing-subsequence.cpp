class Solution {
public:
    int solveRecursion(vector<int>& nums,  int curr, int prev){
        if(curr >= nums.size()) return 0;

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveRecursion(nums, curr+1, curr);
        }
        int exclude = solveRecursion(nums, curr+1, prev);

        int ans = max(include, exclude);
        return ans;
    }

    int solveMemoization(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        if(curr >= nums.size()) return 0;

        // prev+1 : index shifting is requried, because we have passed prev as -1
        // and dp[0][-1] is not a valid way to access a data. Therefore shift one ondex ahead.
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveMemoization(nums, curr+1, curr, dp);
        }
        int exclude = solveMemoization(nums, curr+1, prev, dp);

        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // int ans = solveRecursion(nums, curr, prev);

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solveMemoization(nums, curr, prev, dp);
        return ans;
    }
};