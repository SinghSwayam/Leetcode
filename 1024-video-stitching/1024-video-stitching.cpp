class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> maxEnd(time + 1, 0);
        for (auto &clip : clips) {
            int start = clip[0];
            int end = clip[1];

            if (start <= time) {
                maxEnd[start] = max(maxEnd[start], end);
            }
        }

        int currEnd = 0;
        int farthest = 0;
        int ans = 0;

        for (int i = 0; i < time; i++) {

            farthest = max(farthest, maxEnd[i]);
            if (farthest <= i) {
                return -1;
            }

            if (i == currEnd) {
                ans++;
                currEnd = farthest;

                if (currEnd >= time) {
                    return ans;
                }
            }
        }

        return ans;
    }
};