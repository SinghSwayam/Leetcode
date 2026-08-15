class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        int zeroCnt = 0;

        for (int x : nums) {
            xr ^= x;
            if (x == 0) zeroCnt++;
        }

        if (xr != 0) return nums.size();
        if (zeroCnt == nums.size()) return 0;
        return nums.size() - 1;
    }
};