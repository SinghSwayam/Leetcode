class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        // int ans = 0;
        // for(int bitIdx=0; bitIdx<32; bitIdx++){
        //     int cnt = 0;
        //     for(int i=0; i<n; i++){
        //         if(nums[i] & (1 << bitIdx)){
        //             cnt++;
        //         }
        //     }
        //     if(cnt % 3 != 0){
        //         ans = ans | (1 << bitIdx);
        //     }
        // }
        // return ans;

        // sort(nums.begin(), nums.end());
        // for(int i=1; i<n; i += 3){
        //     if(nums[i-1] != nums[i]){
        //         return nums[i-1];
        //     }
        // }
        // return nums[n-1];

        int ones = 0;
        int twos = 0;
        for(int i=0; i<n; i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};