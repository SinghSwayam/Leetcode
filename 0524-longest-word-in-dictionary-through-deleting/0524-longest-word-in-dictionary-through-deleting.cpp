class Solution {
public:
    static bool cmp(string& a, string& b){
        if(a.length() == b.length())
            return a < b;
        
        return a.length() > b.length();
    }

    bool isMatching(string s, string word){
        int i=0;
        int j=0;

        while(i<s.size() && j<word.size()){
            if(s[i] == word[j]){
                ++j;
            }
            ++i;
        }

        return j == word.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),cmp);

        for(auto& word : dictionary){
            if(isMatching(s,word))
                return word;
        }

        return "";
    }
};