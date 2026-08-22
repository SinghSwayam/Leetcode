class Solution {
public:
    int solveRec(long long n){
        if(n <= 1){
            return 0;
        }

        if((n & 1) == 0){
            return 1 + solveRec(n/2);
        }
        
        return 1 + min(solveRec(n-1), solveRec(n+1));
    }

    int integerReplacement(int n) {
        return solveRec(n);
    }
};