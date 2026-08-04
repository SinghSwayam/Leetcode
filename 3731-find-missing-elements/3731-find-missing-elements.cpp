class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_map<int, int> pres;
        for(int num : nums){
            if(num < mini){
                mini = num;
            }
            if(num > maxi){
                maxi = num;
            }
            pres[num]++;
        }

        vector<int> ans;
        for(int i=mini; i<maxi; i++){
            if(pres[i] < 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};