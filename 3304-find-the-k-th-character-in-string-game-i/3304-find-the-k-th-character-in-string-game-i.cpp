class Solution {
public:
    void findString(string& str, int k){
        
        if(str.length() >= k) return;

        string temp = "";
        for(int i=0;i<str.size();i++){
            char ans = str[i] + 1;
            temp.push_back(ans);
        }
        str += temp;

        findString(str,k);
    }

    char kthCharacter(int k) {
        string str = "a";
        findString(str,k);
        return str[k-1];
    }
};