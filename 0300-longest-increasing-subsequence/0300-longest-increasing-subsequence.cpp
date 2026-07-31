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

    int solveTabulation(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int curr_index = n-1; curr_index >= 0; curr_index--){
            for(int prev_index = curr_index-1; prev_index >= -1; prev_index--){
                int include = 0;
                if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
                    include = 1 + dp[curr_index+1][curr_index+1]; // index shifting required here too
                }
                int exclude = dp[curr_index+1][prev_index+1]; // index shifting required here too

                dp[curr_index][prev_index+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int solveTabulationSpaceOptimized(vector<int>& nums){
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int curr_index = n-1; curr_index >= 0; curr_index--){
            for(int prev_index = curr_index-1; prev_index >= -1; prev_index--){
                int include = 0;
                if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
                    include = 1 + next[curr_index+1]; // index shifting required here too
                }
                int exclude = next[prev_index+1]; // index shifting required here too

                curr[prev_index+1] = max(include, exclude);
            }
            // shifting
            next = curr;
        }
        return next[0];
    }

    int solveBinarySearch(vector<int>& nums){
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // int curr = 0;
        // int prev = -1;
        // int ans = solveRecursion(nums, curr, prev);

        // int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solveMemoization(nums, curr, prev, dp);

        // int ans = solveTabulation(nums);

        // int ans = solveTabulationSpaceOptimized(nums);

        int ans = solveBinarySearch(nums);
        return ans;
    }
};