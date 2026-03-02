class Solution {
public:
    bool isPossibleSolution(vector<int>& weights, int days,int sol){
        int count = 1;
        int currWeight = 0;

        for(int i=0;i<weights.size();i++){
            if(currWeight + weights[i] > sol){
                count++;
                currWeight = weights[i];

                if(count > days) return false;
            }else{
                currWeight += weights[i];
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end());
        int e=accumulate(weights.begin(),weights.end(),0);

        int ans = -1;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(isPossibleSolution(weights,days,mid)){
                ans = mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }

        return ans;
    }
};