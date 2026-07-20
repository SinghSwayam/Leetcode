class Solution {
public:
    int spaceOptimizedTabulation(string& text1, string& text2){
        int n = text1.size();
        int m = text2.size();
        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);

        for(int j=m-1; j>=0;j--){
            for(int i=n-1; i>=0;i--){
                if(text1[i] == text2[j]){
                    curr[i] = 1 + next[i+1];
                }else{
                    curr[i] = max(curr[i+1], next[i]);
                }
            }
            // shifting
            next = curr;
        }
        return curr[0];
    }

    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end());
        int ans = spaceOptimizedTabulation(s, a);
        return ans;
    }
};