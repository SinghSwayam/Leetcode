class Solution {
public:
    int getPivotIndex(vector<int>& arr){
        int s =0;
        int e = arr.size() - 1;
        

        while(s <= e){
            int mid = s+(e-s)/2;
            if(s==e){
                return s;
            }

            if(mid<=e && arr[mid]>arr[mid+1]){
                return mid;   
            }

            if(mid-1 >= s && arr[mid-1]>arr[mid]){
                return mid-1;   
            }

            if(arr[s] > arr[mid]){
                e = mid -1;
            }else{
                s=mid + 1;
            }

        }
        return -1;
    }

    int findMin(vector<int>& nums) {
        if(getPivotIndex(nums) == nums.size() -1 ){
            return nums[0];
        }else{
            return nums[getPivotIndex(nums) + 1];
        }
    }
};