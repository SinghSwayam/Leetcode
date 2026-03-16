class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;

        vector<int> hash(128,0);

        int maxi = 0;

        while(j < s.size()){
            hash[s[j]]++;

            while(hash[s[j]] > 1){
                hash[s[i]]--;
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};