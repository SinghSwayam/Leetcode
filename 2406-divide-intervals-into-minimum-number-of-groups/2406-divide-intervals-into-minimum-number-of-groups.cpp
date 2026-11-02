class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // vector<int> start, end;

        // for (auto& interval : intervals) {
        //     start.push_back(interval[0]);
        //     end.push_back(interval[1]);
        // }

        // sort(start.begin(), start.end());
        // sort(end.begin(), end.end());

        // int i = 0, j = 0;

        // int cnt = 0;
        // int maxCnt = 0;

        // while (i < n) {
        //     if (start[i] <= end[j]) {
        //         cnt++;
        //         i++;
        //     }
        //     else {
        //         cnt--;
        //         j++;
        //     }

        //     maxCnt = max(maxCnt, cnt);
        // }

        // return maxCnt;

        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int ans = 0;

        for(auto& interval : intervals){
            int s = interval[0];
            int e = interval[1];

            while(!pq.empty() && pq.top() < s){
                pq.pop();
            }

            pq.push(e);
            
            int curr = pq.size();
            ans = max(ans, curr);
        }
        return ans;
    }
};