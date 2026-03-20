class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s = 0;
        int zeroCount=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) zeroCount++;
            else{
                nums[s++] = nums[i];
            }
        }

        while(zeroCount--){
            nums[s++] = 0;
        }

    }
};