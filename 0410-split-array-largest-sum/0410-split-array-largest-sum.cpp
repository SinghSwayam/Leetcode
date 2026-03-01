class Solution {
public:
    bool isPossibleSolution(vector<int> &arr,int k,int mid){
        int count=1;
        int currSum = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] > mid) return false;

            if(currSum+arr[i] > mid){
                count++;
                currSum=arr[i];

                if(count > k) return false;
            }else{
                currSum+=arr[i];
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int e=accumulate(nums.begin(),nums.end(),0);

        int ans = -1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(isPossibleSolution(nums,k,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }

        return ans;
    }
};