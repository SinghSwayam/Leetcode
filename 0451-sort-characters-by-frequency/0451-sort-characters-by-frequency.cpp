class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        string ans = "";

        while(!pq.empty()){
            auto [count, ch] = pq.top();
            pq.pop();
            
            ans += string(count, ch);
        }
        return ans;
    }
};