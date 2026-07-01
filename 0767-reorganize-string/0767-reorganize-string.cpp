class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> maxheap;
        for(auto it : mp){
            maxheap.push({it.second, it.first});
        }

        string ans = "";
        while(maxheap.size() > 1){
            auto [firstFreq, firstChar] = maxheap.top();
            maxheap.pop();
            auto [secFreq, secChar] = maxheap.top();
            maxheap.pop();
            
            ans += firstChar;
            ans += secChar;

            if(--firstFreq){
                maxheap.push({firstFreq, firstChar});
            }

            if(--secFreq){
                maxheap.push({secFreq, secChar});
            }
        }

        if(maxheap.size() == 1){
            auto [freq, ch] = maxheap.top();
            maxheap.pop();
            if(freq > 1){
                return "";
            }
            ans += ch;
        }

        return ans;
    }
};