class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(n+1, 0);

        for(int num : nums){
            if(num % k == 0 && num/k <= n){
                freq[num/k]++;
            }
        }

        for(int i=1; i<=n; i++){
            if(freq[i] == 0){
                return i*k;
            }
        }

        return (n + 1) * k;
    }
};