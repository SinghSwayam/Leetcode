class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            if(nums[low] == val){
                swap(nums[low],nums[high]);
                high--;
            }else{
                low++;
            }
        }
        return low;
    }
};