class Solution {
public:
    bool isAnagram(string s, string t) {

        int s_len = s.length();
        int t_len = t.length();
        if(s_len != t_len) return false;

        vector<int> freq(26,0);

        for(int i=0;i<s_len;i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for(int f : freq){
            if(f != 0) return false;
        }

        return true;
    }
};