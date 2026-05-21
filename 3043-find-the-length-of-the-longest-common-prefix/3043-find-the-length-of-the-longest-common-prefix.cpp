class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;

        for(int ele : arr1){
            string s = to_string(ele);

            string pref = "";
            for(char ch : s){
                pref += ch;
                prefixes.insert(pref);
            }
        }

        int ans = 0;

        for(int ele : arr2){
            string s = to_string(ele);

            string pref = "";
            for(char ch : s){
                pref += ch;

                if(prefixes.count(pref)){
                    ans = max(ans, (int)pref.size());
                }
            }
        }

        return ans;
    }
};