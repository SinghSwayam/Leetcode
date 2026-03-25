class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int res = nums[0] + nums[1] + nums[2];
        int size = nums.size();

        for(int i=0;i<size-2;i++){

            int l=i+1;
            int r=size-1;

            while(l<r){
                int currAns = nums[i] + nums[l] + nums[r];
                if(currAns == target) return currAns;

                if(abs(target-currAns) < abs(target-res)){
                    res = currAns;
                }

                if(currAns<target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return res;
    }
};