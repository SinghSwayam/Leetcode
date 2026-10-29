class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int removed = 0;
        int lastEnd = INT_MIN;

        for(auto& interval : intervals){
            if (interval[0] >= lastEnd) {
                lastEnd = interval[1];
            } else {
                removed++;
            }
        }

        return removed;
    }
};