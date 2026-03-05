class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }else{
            return false;
        }
    }

    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;

        while(i<j){
            if(!isVowel(s[i])){
                i++;
            }else if(!isVowel(s[j])){
                j--;
            }else{
                swap(s[i++],s[j--]);
            }
        }

        return s;
    }
};