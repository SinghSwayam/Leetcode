class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> digits;
        int sum = 0;

        while(n > 0){
            int d = n % 10;
            if(d != 0){
                digits.push_back(d);
                sum += d;
            }
            n /= 10;
        }

        long long num = 0;
        for(int i=digits.size()-1; i>=0;i--){
            num = num * 10 + digits[i];
        }

        return num * sum;
    }
};