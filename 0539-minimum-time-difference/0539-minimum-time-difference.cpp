class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for(int i=0;i<timePoints.size();i++){
            string currStr = timePoints[i];

            int hrs = stoi(currStr.substr(0,2));
            int min = stoi(currStr.substr(3,2));

            int totalMin = hrs*60 + min;

            minutes.push_back(totalMin);
        }

        sort(minutes.begin(),minutes.end());

        int minDiff = INT_MAX;
        int n=minutes.size();

        for(int i=0;i<n-1;i++){
            int diff = minutes[i+1] - minutes[i];
            minDiff = min(diff,minDiff);
        }

        int lastDiff = (minutes[0] + 1440) - minutes[n-1];
        minDiff = min(lastDiff,minDiff);

        return minDiff;

    }
};