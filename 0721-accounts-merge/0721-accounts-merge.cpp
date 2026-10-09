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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mp;
        DisjointSet ds(n);

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(mp.find(email) == mp.end()){
                    mp[email] = i;
                }else{
                    ds.unionBySize(i, mp[email]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto it : mp){
            string mail = it.first;
            int node = ds.find(it.second);
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i=0; i<n; i++){
            if(mergedMail[i].size() == 0) continue;
            
            sort(mergedMail[i].begin(), mergedMail[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
};