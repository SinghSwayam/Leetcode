class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num1Size =nums1.size();
        int num2Size = nums2.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i<num1Size && j<num2Size){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i++]);
            }else{
                ans.push_back(nums2[j++]);
            }
        }

        while(i<num1Size){
            ans.push_back(nums1[i++]);
        }

        while(j<num2Size){
            ans.push_back(nums2[j++]);
        }

        int n = ans.size();
        double median;
        if(n%2 == 1){
            return ans[n/2];
        }else{
            return (ans[(n/2) - 1] + ans[(n/2)]) / 2.0;
        }


    }
};