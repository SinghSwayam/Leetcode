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

    int hammingDistance(int x, int y) {
        int setBits = x ^ y;
        int ans = countSetBits(setBits);
        return ans;
    }
};