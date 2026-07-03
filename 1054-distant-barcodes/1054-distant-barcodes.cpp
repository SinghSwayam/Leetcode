class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> mp;
        for(int barcode : barcodes){
            mp[barcode]++;
        }

        priority_queue<pair<int, int>> maxheap;
        for(auto it : mp){
            maxheap.push({it.second, it.first});
        }

        vector<int> ans;
        while(maxheap.size() > 1){
            auto [freq_1, num_1] = maxheap.top();
            maxheap.pop();
            auto [freq_2, num_2] = maxheap.top();
            maxheap.pop();

            ans.push_back(num_1);
            ans.push_back(num_2);

            if(--freq_1){
                maxheap.push({freq_1, num_1});
            }

            if(--freq_2){
                maxheap.push({freq_2, num_2});
            }
        }

        if (!maxheap.empty()) {
            ans.push_back(maxheap.top().second);
        }

        return ans;
    }
};