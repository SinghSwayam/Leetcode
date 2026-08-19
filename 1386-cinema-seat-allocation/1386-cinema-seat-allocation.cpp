class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;

        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }

        int ans = (n - reserved.size()) * 2;

        for (auto &[row, seats] : reserved) {
            bool left = true;    // seats 2-5
            bool middle = true;  // seats 4-7
            bool right = true;   // seats 6-9

            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }

            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }

            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};