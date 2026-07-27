class Solution {
public:
    static bool cmp(int a, int b){
        return a > b;
    }
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return (nums[0] - 1) * (nums[1] - 1);
    }
};