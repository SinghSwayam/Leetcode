class Solution {
public:
    vector<int> d;
    // DP State: [pos][waviness_sum][prev2_digit][prev_digit][is_strictly_smaller][is_non_zero_started]
    long long dp[30][30][11][11][2][2];

    long long solve(int pos, int sum, int prev2, int prev, bool small, bool nz) {
        if(pos == d.size()) return sum;
        
        if(dp[pos][sum][prev2][prev][small][nz] != -1) {
            return dp[pos][sum][prev2][prev][small][nz];
        }

        // limit is 9 if we are already smaller than the prefix, else it's the actual digit
        int lim = small ? 9 : d[pos];
        long long ans = 0;
        
        for(int i = 0; i <= lim; i++) {
            bool nsmall = (small || i < d[pos]); // Becomes true if we pick a smaller digit
            bool nnz = (nz || i != 0);           // Becomes true once we place the first non-zero digit

            if(nnz) {
                // leading zeros ended
                int nprev2 = prev;
                int nprev = i;
                int nsum = sum;
                
                // If we have at least 3 digits to compare, check for a wave
                if(prev2 != 10 && prev != 10) {
                    // peak: prev2 < prev > current
                    nsum += (prev2 < prev && prev > i);
                    // valley: prev2 > prev < current
                    nsum += (prev2 > prev && prev < i);
                }
                ans += solve(pos + 1, nsum, nprev2, nprev, nsmall, nnz);
            } else {
                // processing leading zeros
                ans += solve(pos + 1, sum, prev2, prev, nsmall, nnz);
            }
        }
        
        // Memoize and return
        dp[pos][sum][prev2][prev][small][nz] = ans;
        return ans;
    }

    long long count(long long num) {
        if(num == 0) return 0;
        d.clear();
        while(num) {
            d.push_back(num % 10);
            num /= 10;
        }
        reverse(d.begin(), d.end());
        memset(dp, -1, sizeof(dp));
        // start dp by pos=0, sum=0, prev2=10, prev=10, small=0, nz=0
        return solve(0, 0, 10, 10, 0, 0);
    }

    long long totalWaviness(long long num1, long long num2) {
        // digit dp range technique : ans(R) - ans(L-1)
        return count(num2) - count(num1 - 1);
    }
};