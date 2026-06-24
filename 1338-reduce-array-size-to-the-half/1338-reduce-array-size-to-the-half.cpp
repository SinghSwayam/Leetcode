class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }

        vector<vector<int>> vec;
        for(auto it : mp){
            vec.push_back({it.second, it.first});
        }
        sort(vec.rbegin(), vec.rend());

        int x = arr.size();
        int sum=0, ans=0;

        for(int i=0; i<vec.size(); i++){
            sum += vec[i][0];
            ans++;
            if(sum*2 >= x) break;
        }
        return ans;
    }
};