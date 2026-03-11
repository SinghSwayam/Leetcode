class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26,0);

        for(int i=0;i<s.size();i++){
            count[s[i] - 'a']++;
        }

        string ans;

        for(int i=0;i<order.size();i++){
            while(count[order[i] - 'a'] > 0){
                ans.push_back(order[i]);
                count[order[i] - 'a']--;
            }
        }

        for(int i=0;i<count.size();i++){
            while(count[i] > 0){
                ans.push_back(i+'a');
                count[i]--;
            }
        }

        return ans;
    }
};