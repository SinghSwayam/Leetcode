class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits)
            freq[d]++;

        int ans = 0;
        for (int num = 100; num <= 999; num++) {
            if (num % 2 != 0)
                continue;

            int x = num;
            vector<int> used(10, 0);
            for (int i = 0; i < 3; i++) {
                used[x % 10]++;
                x /= 10;
            }

            bool possible = true;
            for (int d = 0; d < 10; d++) {
                if (used[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible) ans++;
        }
        return ans;
    }
};