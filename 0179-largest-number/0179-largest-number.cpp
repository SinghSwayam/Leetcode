class Solution {
public:
    static bool compare(string a,string b){
        return a+b > b+a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(auto num : nums){
            snums.push_back(to_string(num));
        }

        sort(snums.begin(),snums.end(),compare);

        if(snums[0] == "0") return "0";

        string ans;
        for(auto s : snums){
            ans += s;
        }

        return ans;
    }
};