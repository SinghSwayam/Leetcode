class Solution {
public:
    bool solveRec(vector<int>& nums, int i, int target){
        if(target == 0) return true;
        if(i >= nums.size() || target < 0) return false;

        bool inc = false;
        if(target - nums[i] >= 0){
            inc = solveRec(nums, i+1, target - nums[i]);
        }
        bool exc = solveRec(nums, i+1, target);

        return (inc || exc);
    }

    bool solveMemo(vector<int>& nums, int i, int target, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i >= nums.size() || target < 0) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool inc = false;
        if(target - nums[i] >= 0){
            inc = solveMemo(nums, i+1, target - nums[i], dp);
        }
        bool exc = solveMemo(nums, i+1, target, dp);

        return dp[i][target] = (inc || exc);
    }

    bool solveTab(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        for(int row=0; row<=n; row++){
            dp[row][0] = 1;
        }

        for(int index = n-1; index >= 0; index--){
            for(int t=1; t<=target; t++){
                bool inc = false;
                if(t - nums[index] >= 0){
                    inc = dp[index+1][t - nums[index]];
                }
                bool exc = dp[index+1][t];

                dp[index][t] = (inc || exc);
            }
        }
        return dp[0][target];
    }

    bool solveTabSpaceOptimized(vector<int>& nums, int target){
        int n = nums.size();
        
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);

        curr[0] = 1;
        next[0] = 1;

        for(int index = n-1; index >= 0; index--){
            for(int t=1; t<=target; t++){
                bool inc = false;
                if(t - nums[index] >= 0){
                    inc = next[t - nums[index]];
                }
                bool exc = next[t];

                curr[t] = (inc || exc);
            }
            next = curr;
        }
        return next[target];
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num : nums){
            total += num;
        }

        if(total & 1) return false;

        int target = total/2;
        // return solveRec(nums, 0, target);

        // vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, -1));
        // return solveMemo(nums, 0, target, dp);

        // return solveTab(nums, target);

        return solveTabSpaceOptimized(nums, target);
    }
};