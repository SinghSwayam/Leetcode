class Solution {
public:
    void solve(unordered_map<char, string>& mp,vector<string>& finalAns,string& currAns,string& digits,int index){
        if(index >= digits.size()){
            finalAns.push_back(currAns);
            return;
        }

        string currNumLetter = mp[digits[index]];

        for(int i=0;i<currNumLetter.size();i++){
            currAns.push_back(currNumLetter[i]);
            solve(mp,finalAns,currAns,digits,index+1) ;
            currAns.pop_back();
        }  

    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, 
            {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, 
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        string currAns="";
        vector<string> finalAns;

        solve(mp,finalAns,currAns,digits,0);
        return finalAns;
    }
};