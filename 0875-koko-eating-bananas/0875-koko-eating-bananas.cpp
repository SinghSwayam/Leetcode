class Solution {
public:
    bool isPosibleSolution(vector<int>& piles, int h, int sol){
        long long hours = 0;

        for(auto pile : piles){
            hours += (pile + sol - 1)/sol;

            if(hours > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(),piles.end());

        int ans = -1;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(isPosibleSolution(piles,h,mid)){
                ans = mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }

        return ans;
    }
};