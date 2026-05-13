class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> dif(2*limit + 2, 0);

        for(int i=0;i<n/2;i++){
            int a = nums[i];
            int b = nums[n-1-i];

            int x = min(a,b);
            int y = max(a,b);

            dif[2] += 2;

            dif[x+1] -= 1;

            dif[a+b] -= 1;

            dif[a+b+1] += 1;

            dif[y+limit+1] += 1; 
        }

        int ans = INT_MAX;
        int cur = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            cur += dif[s];
            ans = min(ans, cur);
        }
        return ans;

    }
};