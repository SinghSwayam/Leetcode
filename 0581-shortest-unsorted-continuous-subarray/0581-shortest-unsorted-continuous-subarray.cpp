class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low = -1;
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i-1] > nums[i]){
                low = i-1;
                break;
            }
        }

        if(low == -1) return 0;

        int high = n-1;
        for(int i = n-1; i > 0; i--) {
            if(nums[i-1] > nums[i]) {
                high = i;
                break;
            }
        }

        int mn = INT_MAX;
        int mx = INT_MIN;

        for(int i=low; i<=high; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        while(low>0 && nums[low-1]>mn) {
            low--;
        }

        while(high<n-1 && nums[high+1]<mx) {
            high++;
        }

        return high-low+1;
    }
};