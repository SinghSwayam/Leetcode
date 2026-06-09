class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int num : nums){
            maxi = max(num,maxi);
            mini = min(num,mini);
        }

        long long ans = (long long)(maxi - mini) * k;
        return ans;
    }
};