class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // for(int num : nums){
        //     mp[num]++;
        // }
        // vector<int> ans;
        // for(auto it : mp){
        //     if(it.second == 1){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;

        long long xorr = 0;
        for(int num : nums){
            xorr = xorr ^ num;
        }

        int rightmost = xorr & -xorr;
        int b1 = 0;
        int b2 = 0;

        for(int num :nums){
            if(num & rightmost){
                b1 = b1 ^ num;
            }else{
                b2 = b2 ^ num;
            }
        }
        return {b1, b2};
    }
};