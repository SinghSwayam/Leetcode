class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(auto pat : patterns){
            if(word.find(pat) != string::npos){
                ans++;
            }
        }
        return ans;
    }
};