class Solution {
public:
    bool solve(vector<int>& counts, vector<int>& quantity,int ithCustomer){
        if(ithCustomer == quantity.size()) return true;

        for(int i=0;i<counts.size();i++){
            if(counts[i] >= quantity[ithCustomer]){
                counts[i] -= quantity[ithCustomer];
                if(solve(counts,quantity,ithCustomer+1)){
                    return true;
                }
                counts[i] += quantity[ithCustomer];
            }
        }

        return false;

    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }

        vector<int>counts;
        for(auto it : mp){
            counts.push_back(it.second);
        }

        sort(quantity.rbegin(),quantity.rend());

        return solve(counts,quantity,0);
    }
};