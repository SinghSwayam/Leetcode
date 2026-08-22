class Solution {
public:
    bool checkDivisibility(int n) {
        int dSum = 0;
        int dProd = 1;

        int temp = n;

        while(temp){
            int digit = temp % 10;
            temp /= 10;

            dSum += digit;
            dProd *= digit;
        }

        return (n % (dSum + dProd)) == 0;
    }
};