class Solution {
public:
    bool isPossibleSolution(vector<int>& arr, int m, int sol){
        int count = 1;
        int pos = arr[0];

        for(int i=1;i<arr.size();i++){
            if(arr[i] - pos >= sol){
                count++;
                pos = arr[i];
            }

            if(count >= m) return true;
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int s = 0;
        int e = position.back() - position[0];

        int ans= -1;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossibleSolution(position,m,mid)){
                ans = mid;
                s = mid+1;
            }else{
                e =mid-1;
            }
        }

        return ans;

    }
};