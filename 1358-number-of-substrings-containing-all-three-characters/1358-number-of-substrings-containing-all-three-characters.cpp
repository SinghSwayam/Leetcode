class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastPos = {-1,-1,-1};
        int ans = 0;
        int len = s.size();

        for(int i=0; i<len; i++){
            lastPos[s[i] - 'a'] = i;
            int currLen = min({lastPos[0],lastPos[1],lastPos[2]});

            ans += (1 + currLen);
        }
        return ans;
    }
};