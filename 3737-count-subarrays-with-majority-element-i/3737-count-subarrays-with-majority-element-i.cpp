class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int targetCount = 0;
            for(int j=i; j<n; j++){
                if(nums[j] == target){
                    targetCount++;
                }

                int len = j-i+1;

                if(targetCount*2 > len){
                    ans++;
                }
            }
        }
        return ans;
    }
};