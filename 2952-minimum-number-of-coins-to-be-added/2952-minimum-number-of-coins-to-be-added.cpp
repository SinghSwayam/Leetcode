class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());

        long long miss = 1;
        int added=0;
        int i=0;
        int n = coins.size();

        while (miss<=target) {
            if (i<n && coins[i]<=miss) {
                miss+=coins[i];
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