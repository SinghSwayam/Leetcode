class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] != 9){
            digits[n-1] += 1;
            return digits;
        }

        reverse(digits.begin(), digits.end());
        int carry = 1;
        digits[0] = 0;
        for(int i=1; i<n; i++){
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if(carry != 0){
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};