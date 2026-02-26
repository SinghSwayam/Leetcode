class Solution {
public:
    int findPivot(vector<int>& nums) {
       int s=0;
       int e=nums.size()-1;
       
       while(s<=e){
         if(s == e) return s;

         int mid = s + (e-s)/2;

         if((mid+1 <= e) && (nums[mid] > nums[mid+1])){
            return mid;
         }else if((mid-1 >= s) && (nums[mid-1] > nums[mid])){
            return mid-1;
         }else if(nums[mid] < nums[s]){
            e=mid-1;
         }else{
            s=mid+1;
         }
       }
       return -1;
    }

    int bs(vector<int>& nums,int s,int e, int target){
        while(s<=e){
            int mid = s+(e-s)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int ans = 0;

        if(target >= nums[0] && target<=nums[pivot]){
            ans = bs(nums,0,pivot,target);
        }else{
            ans = bs(nums,pivot+1,nums.size()-1,target);
        }

        return ans;
    }
};