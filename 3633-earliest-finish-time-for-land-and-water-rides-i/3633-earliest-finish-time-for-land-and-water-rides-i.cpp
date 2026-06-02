class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            int landfinish = landStartTime[i] + landDuration[i];
            for(int j=0;j<m;j++){
                int finish = max(landfinish,waterStartTime[j]) + waterDuration[j];
                ans = min(ans,finish);
            }
        }

        for(int i=0;i<m;i++){
            int waterfinish = waterStartTime[i] + waterDuration[i];
            for(int j=0;j<n;j++){
                int finish = max(waterfinish,landStartTime[j]) + landDuration[j];
                ans = min(ans,finish);
            }
        }
        return ans;
    }
};