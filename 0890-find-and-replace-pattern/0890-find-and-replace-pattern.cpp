class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> hash(256,0);
        vector<bool> is_mapped(256,false);

        for(int i=0;i<s.length();i++){
            if(hash[s[i]] == 0 && is_mapped[t[i]] == false){
                hash[s[i]] = t[i];
                is_mapped[t[i]] = true;
            }
        }

        for(int i=0;i<s.length();i++){
            if(char(hash[s[i]]) != t[i]){
                return false;
            }
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for(string word : words){
            if(isIsomorphic(word,pattern)){
                ans.push_back(word);
            }
        }

        return ans;
    }
};