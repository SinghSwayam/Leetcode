class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());

        long long miss = 1;
        int added=0;
        int i=0;
        int s = nums.size();

        while (miss<=n) {
            if (i<s && nums[i]<=miss) {
                miss+=nums[i];
                i++;
            }
            else {
                miss +=miss;
                added++;
            }
        }

        return added;
    }
};