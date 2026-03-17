class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;

        int maxi=0;

        while(l<r){
            int minHeight = min(height[l],height[r]);
            int ans = minHeight * (r-l);
            maxi = max(maxi,ans);

            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }

        return maxi;

    }
};