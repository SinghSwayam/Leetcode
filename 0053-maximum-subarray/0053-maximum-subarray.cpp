class Solution {
public:
    int solveMaxSubArray(vector<int>& nums,int s,int e){
        if(s == e) return nums[s];

        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int mid = s + (e-s)/2;

        int maxLeftSum = solveMaxSubArray(nums,s,mid);
        int maxRightSum = solveMaxSubArray(nums,mid+1,e);

        int leftBorderSum=0, rightBorderSum=0;
        for(int i=mid; i>=s;i--){
            leftBorderSum += nums[i];
            if(leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
        }

        for(int i=mid+1; i<=e;i++){
            rightBorderSum += nums[i];
            if(rightBorderSum > maxRightBorderSum) maxRightBorderSum = rightBorderSum;
        }

        int crossBorderSum = maxRightBorderSum + maxLeftBorderSum;

        return max({maxLeftSum,maxRightSum,crossBorderSum});
    }

    int maxSubArray(vector<int>& nums) {
        return solveMaxSubArray(nums,0,nums.size()-1);
    }
};