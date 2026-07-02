class Compare{
    public:
        bool operator()(pair<int, string>& a, pair<int, string>& b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string word : words){
            mp[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> maxheap;
        for(auto it : mp){
            maxheap.push({it.second, it.first});
        }

        vector<string> ans;
        while(k--){
            auto [freq, word] = maxheap.top(); maxheap.pop();
            ans.push_back(word);
        }

        return ans;
    }
};