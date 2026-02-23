class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualSum = (n * (n+1)) / 2;
        int currentSum = 0;
        for(auto i : nums){
          currentSum += i;
        }

        int element = actualSum - currentSum;
        return element;

    }
};