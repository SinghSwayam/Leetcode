class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int bitIdx=0; bitIdx<32; bitIdx++){
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(nums[i] & (1 << bitIdx)){
                    cnt++;
                }
            }
            if(cnt % 3 != 0){
                ans = ans | (1 << bitIdx);
            }
        }
        return ans;
    }
};