class Solution {
public:
    int countSetBits(int n){
        int cnt = 0;
        while(n){
            n = n & n-1;
            cnt++;
        }
        return cnt;
    }

    int minBitFlips(int start, int goal) {
        int setBits = start ^ goal;
        int ans = countSetBits(setBits);
        return ans;
    }
};