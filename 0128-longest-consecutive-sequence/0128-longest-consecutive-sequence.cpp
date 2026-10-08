class DisjointSet{

public: 
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(node == parent[node])
            return node;
        
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int idx = 0;
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num] = idx++;
        }

        DisjointSet ds(nums.size());

        for(auto [num, id] : mp){
            if(mp.find(num-1) != mp.end()){
                ds.unionBySize(id, mp[num-1]);
            }
            if(mp.find(num+1) != mp.end()){
                ds.unionBySize(id, mp[num+1]);
            }
        }

        int maxSize = INT_MIN;
        for(int i=0; i<idx; i++){
            if(ds.find(i) == i) {
                maxSize = max(maxSize, ds.size[i]);
            }
        }
        return maxSize;
    }
};