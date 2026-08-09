class Solution {
public:
    bool solveRec(vector<int>& nums, int target, int i){
        if(target == 0) return true;
        if(i >= nums.size() || target < 0) return false;

        bool inc = false;
        if(target - nums[i] >= 0){
            inc = solveRec(nums, target - nums[i], i+1);
        }
        bool exc = solveRec(nums, target, i+1);

        return (inc || exc);
    }

    bool solveMemo(vector<int>& nums, int target, int i, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i >= nums.size() || target < 0) return false;

        if(dp[target][i] != -1) return dp[target][i];

        bool inc = false;
        if(target - nums[i] >= 0){
            inc = solveMemo(nums, target - nums[i], i+1, dp);
        }
        bool exc = solveMemo(nums, target, i+1, dp);

        return dp[target][i] = (inc || exc);
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num : nums){
            total += num;
        }

        if((total % 2) == 1) return false;

        int target = total/2;
        // return solveRec(nums, target, 0);

        vector<vector<int>> dp(target+1, vector<int>(nums.size()+1, -1));
        return solveMemo(nums, target, 0, dp);
    }
};