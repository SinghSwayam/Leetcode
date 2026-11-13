class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();

        for (int curr = n; curr > 1; curr--) {
            int maxIdx = max_element(arr.begin(),arr.begin() + curr) - arr.begin();

            if (maxIdx == curr - 1) continue;

            if (maxIdx != 0) {
                reverse(arr.begin(), arr.begin() + maxIdx + 1);
                ans.push_back(maxIdx + 1);
            }

            reverse(arr.begin(), arr.begin() + curr);
            ans.push_back(curr);
        }

        return ans;
    }
};