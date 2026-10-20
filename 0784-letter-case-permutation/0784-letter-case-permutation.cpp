class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                n++;
            }
        }

        int subsets = 1 << n;
        vector<string> ans;
        for(int i=0; i<subsets; i++){
            string curr = s;
            int bitIdx = 0;

            for(int j=0; j<s.size(); j++){
                if(s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z'){
                    if((i >> bitIdx) & 1){
                        curr[j] = toupper(s[j]);
                    }else{
                        curr[j] = tolower(s[j]);
                    }
                    bitIdx++;
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};