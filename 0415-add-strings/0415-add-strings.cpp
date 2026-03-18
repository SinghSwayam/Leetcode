class Solution {
public:
    void solveRE(string& num1,int p1, string& num2,int p2, int carry, string& ans){

        if(p1<0 && p2<0 && carry==0){
            if(carry > 0){
                ans += carry + '0';
            }
            return;
        }

        int n1 = (p1 >= 0) ? num1[p1] - '0' : 0;
        int n2 = (p2 >= 0) ? num2[p2] - '0' : 0;
        int currSum = n1+n2+carry;
        int digit = currSum % 10;
        carry = currSum / 10;
        ans += digit + '0';

        solveRE(num1,p1-1,num2,p2-1,carry,ans);
    
    }

    string addStrings(string num1, string num2) {
        string ans = "";
        solveRE(num1,num1.size()-1,num2,num2.size()-1,0,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};