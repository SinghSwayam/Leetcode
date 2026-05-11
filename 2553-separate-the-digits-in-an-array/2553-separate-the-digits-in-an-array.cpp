class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        for(int num : nums){
            if(num >= 10){
                while(num > 0){
                    int digit = num % 10;
                    st.push(digit);
                    num /= 10;
                }
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }else{
                ans.push_back(num);
            }
        }
        return ans;
    }
};