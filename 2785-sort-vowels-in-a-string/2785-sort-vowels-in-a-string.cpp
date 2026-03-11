class Solution {
public:

    bool isVowel(char c){
        c = tolower(c);
        
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s) {
        vector<char> crr;
        for(char ch : s){
            if(isVowel(ch)){
                crr.push_back(ch);
            }
        }

        sort(crr.begin(),crr.end());

        int k=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i] = crr[k++];
            }
        }


        return s;

    }
};