class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while(s < e){
            int mid = s +(e-s)/2;

            if(mid % 2 == 0){
                if(mid+1<= nums.size()-1 && nums[mid] == nums[mid+1]){
                    s = mid + 2;
                }else{
                    e = mid;
                }
            }else{
                if(mid-1>= 0 && nums[mid] == nums[mid-1]){
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            } 
        }
        return nums[s];
    }
};