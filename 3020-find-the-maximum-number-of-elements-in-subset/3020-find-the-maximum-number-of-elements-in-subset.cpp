class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long , int> freq;
        for(int num : nums){
            freq[num]++;
        }

        int ans = 1;

        if(freq.count(1)){
            ans = max( ans, (freq[1] % 2) ? freq[1] : freq[1]-1);
        }

        for(auto& [x, f] : freq){
            if(x == 1) continue;

            long long curr = x;
            int len = 0;

            while(freq.count(curr) && freq[curr] >= 2){
                len += 2;
                if (curr > LLONG_MAX / curr) break;
                curr *= curr;
            }

            if(freq.count(curr) && freq[curr] == 1){
                len++;
            }else{
                len--;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};