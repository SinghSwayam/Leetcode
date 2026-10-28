class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> jobs(n);
        for(int i=0; i<n; i++){
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());

        vector<int> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = jobs[i][0];
        }

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int next = lower_bound(starts.begin() + i + 1,starts.end(),jobs[i][1]) - starts.begin();

            int take = jobs[i][2] + dp[next];
            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};