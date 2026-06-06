class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int rightSum = 0;
        for(int i : nums){
            rightSum += i;
        }
        int leftSum = 0;
        for(int i=0;i<n;i++){
            rightSum -= nums[i];
            ans[i] = abs(rightSum - leftSum);
            leftSum += nums[i];
        }
        return ans;
    }
};