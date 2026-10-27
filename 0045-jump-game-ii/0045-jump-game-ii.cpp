class Solution {
public:
    int solve(vector<int>& nums, int i){
        if(i >= nums.size() - 1) return 0;

        int ans = INT_MAX;
        for(int j=1; j<=nums[i]; j++){
            int jump = solve(nums, i+j);
            if(jump != INT_MAX){
                ans = min(ans,1 + jump);
            }
        }
        return ans;
    }

    int solveMemoization(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()-1) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for(int j=1; j<=nums[i]; j++){
            int jump = solveMemoization(nums, i+j, dp);
            if(jump != INT_MAX){
                ans = min(ans,1 + jump);
            }
        }
        return dp[i] = ans;
    }

    int solveGreedy(vector<int>& nums){
        int jumps = 0;
        int l=0;
        int r=0;

        while(r < nums.size()-1){
            int farthest = 0;
            for(int i=l; i<=r; i++){
                farthest = max(i + nums[i], farthest);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }

    int jump(vector<int>& nums) {
        // int ans = solve(nums, 0);

        // vector<int> dp(nums.size()+1, -1);
        // int ans = solveMemoization(nums, 0, dp);

        int ans = solveGreedy(nums);
        
        return ans;
    }
};