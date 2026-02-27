class Solution {
public:
    int lowerBound(vector<int>& arr, int x){
        int s=0;
        int e=arr.size()-1;
        int ans = arr.size();

        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid] >= x){
                ans=mid;
                e=mid-1;
            }else if(x>arr[mid]){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        

        int high=lowerBound(arr,x);
        int low=high-1;

        while(k--){
            if(low<0){
                high++;
            }else if(high>=arr.size()){
                low--;
            }else if(x-arr[low] > arr[high]-x){
                high++;
            }else{
                low--;
            }
        }

        return vector<int>(arr.begin() + low + 1,arr.begin() + high);


    }
};