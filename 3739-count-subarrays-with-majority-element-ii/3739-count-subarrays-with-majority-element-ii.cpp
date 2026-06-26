class Fenwick{
    public:
    vector<int> bit;
    int n;

    Fenwick(int n){
        this->n = n;
        bit.assign(n+1,0);
    }

    void update(int idx, int val){
        while(idx <= n){
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n+1;
        Fenwick bit(2*n+5);

        long long ans = 0;
        int pref = 0;

        bit.update(offset,1);

        for(int num : nums){
            if(num == target)
                pref += 1;
            else
                pref -= 1;

            int idx = pref + offset;

            ans += bit.query(idx-1);

            bit.update(idx,1);
        }
        return ans;
    }
};