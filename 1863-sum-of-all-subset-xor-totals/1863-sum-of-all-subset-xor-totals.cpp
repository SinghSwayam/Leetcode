class Solution {
public:

    int solve(vector<int>& nums,int i,int currXOR){
        if(i==nums.size()){
            return currXOR;
        }

        int inc =solve(nums,i+1,currXOR^nums[i]);
        int exc =solve(nums,i+1,currXOR);

        return inc+exc;

    }

    int subsetXORSum(vector<int>& nums) {
        int ans =solve(nums,0,0);
        return ans;
    }
};