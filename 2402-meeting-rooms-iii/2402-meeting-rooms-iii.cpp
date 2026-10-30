class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        priority_queue<pair<long long, int>,
               vector<pair<long long, int>>,
               greater<pair<long long, int>>> busy; // {endingTime, roomNumber}

        vector<int> count(n, 0);

        for (auto& meeting : meetings){
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();

                busy.push({end, room});
                count[room]++;
            }else{
                auto [freeTime, room] = busy.top();
                busy.pop();

                long long newEnd = freeTime + duration;
                busy.push({newEnd, room});
                count[room]++;
            }
        }
        int ans = 0;
        for (int i=1;i<n;i++) {
            if (count[i] > count[ans]) {
                ans=i;
            }
        }
        return ans;
    }
};