class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string& word : words){
            int sum = 0;
            for(char ch : word){
                sum += weights[ch - 'a'];
            }
            int val = sum % 26;
            ans.push_back(('z' - val));
        }
        return ans;
    }
};