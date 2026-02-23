class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groupCount;
        int c = 1;
        for(int i=1;i<s.size();i++){
            if(s[i] != s[i-1]){
                groupCount.push_back(c);
                c = 1;
            }else{
                c++;
            }
        }
        groupCount.push_back(c);

        int ans = 0;
        for(int i=1;i<groupCount.size();i++){
            ans += min(groupCount[i],groupCount[i-1]);
        }
        return ans;
    }
};