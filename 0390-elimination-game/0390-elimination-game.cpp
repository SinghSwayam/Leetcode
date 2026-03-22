class Solution {
public:
    int solve(int n, bool leftToRight){
        if(n == 1) return 1;

        if(leftToRight){
            return 2 * solve(n/2,false);
        }else{
            if(n%2 == 0){
                return 2 * solve(n/2,true)-1;
            }else{
                return 2 * solve(n/2,true);
            }
        }

        return -1;
    }

    int lastRemaining(int n) {
        return solve(n,true);
    }
};