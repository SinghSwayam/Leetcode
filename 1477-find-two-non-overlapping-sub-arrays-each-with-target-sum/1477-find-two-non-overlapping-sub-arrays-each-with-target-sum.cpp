class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int prefix = 0;
        int ans = INT_MAX;
        int minLen = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            if (mp.count(prefix - target)) {
                int j = mp[prefix - target];
                int len = i - j;
                
                if (j >= 0 && best[j] != INT_MAX) {
                    ans = min(ans, len + best[j]);
                }
                
                minLen = min(minLen, len);
            }
            best[i] = minLen;
            mp[prefix] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};