class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l=0, ones=0;
        string ans = "";

        for(int r=0; r<n; r++){
            if(s[r] == '1'){
                ones++;
            }

            while(ones > k){
                if(s[l] = '1'){
                    ones--;
                }
                l++;
            }

            if(ones == k){
                while(l <= r && s[l] == '0'){
                    l++;
                }
                string curr = s.substr(l, r-l+1);

                if(ans.empty() || (curr.size() < ans.size()) || (curr.size() == ans.size() && curr < ans)){
                    ans = curr;
                }
            }
        }
        return ans;
    }
};