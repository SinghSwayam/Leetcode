class Solution {
public:
    vector<int> d;
    long long dp[30][30][11][11][2][2];

    long long solve(int pos,int sum,int prev2,int prev,bool small,bool nz){
        if(pos == d.size()) return sum;
        if(dp[pos][sum][prev2][prev][small][nz] != -1) {
            return dp[pos][sum][prev2][prev][small][nz];
        }

        int lim = small ? 9 : d[pos];
        long long ans = 0;
        for(int i=0;i<=lim;i++){
            bool nsmall = (small || i<d[pos]);
            bool nnz = (nz || i!=0);

            if(nnz){
                int nprev2 = prev;
                int nprev = i;
                int nsum = sum;
                if(prev2!=10 && prev!=10){
                    nsum += (prev2 < prev && prev > i);
                    nsum += (prev2 > prev && prev < i);
                }
                ans += solve(pos+1,nsum,nprev2,nprev,nsmall,nnz);
            }else{
                ans += solve(pos+1,sum,prev2,prev,nsmall,nnz);
            }
        }
        dp[pos][sum][prev2][prev][small][nz] = ans;
        return ans;
    }

    long long count(long long num){
        if(num == 0) return 0;
        d.clear();
        while(num){
            d.push_back(num%10);
            num /= 10;
        }
        reverse(d.begin(),d.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,0,10,10,0,0);
    }

    long long totalWaviness(long long num1, long long num2) {
        return count(num2) - count(num1-1);
    }
};