class Solution {
public:
    long long lcm_ll(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // lcms[s] = LCMs of along long subsets containing s coins
        vector<vector<long long>> lcms(n + 1);

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long curLCM = 1;
            int bits = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    ++bits;
                    curLCM = lcm_ll(curLCM, coins[i]);
                }
            }

            lcms[bits].push_back(curLCM);
        }

        // Count distinct valid amounts <= x
        auto count = [&](long long x) -> long long {
            long long ans = 0;

            for (int sz = 1; sz <= n; ++sz) {
                for (long long L : lcms[sz]) {
                    long long contribution = x / L;

                    if (sz & 1)
                        ans += contribution;
                    else
                        ans -= contribution;
                }
            }

            return ans;
        };

        // The kth answer cannot exceed k * minimum coin.
        long long lo = 1;
        long long hi = 1LL * k * (*min_element(coins.begin(), coins.end()));

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};