class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }

public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int maxUnits=0;
        for(int i=0; i<n && truckSize > 0; i++){
            int boxes = min(boxTypes[i][0], truckSize);
            maxUnits += boxes * boxTypes[i][1];
            truckSize -= boxes;
        }
        return maxUnits;
    }
};