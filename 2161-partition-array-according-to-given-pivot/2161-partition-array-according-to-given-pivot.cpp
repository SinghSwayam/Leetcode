class Solution {
public:
    
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left,mid,right,ans;
        for(auto i : nums){
            if(i<pivot) left.push_back(i);
            else if(i==pivot) mid.push_back(i);
            else right.push_back(i);
        }

        for(auto i : left){
            ans.push_back(i);
        }
        for(auto i : mid){
            ans.push_back(i);
        }
        for(auto i : right){
            ans.push_back(i);
        }
        return ans;
    }
};