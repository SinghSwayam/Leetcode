class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();
        // L -> R
        for(int i=1;i<m;i++){
            int distance = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + distance);
        }

        // R -> L
        for(int i=m-2;i>=0;i--){
            int distance = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1],restrictions[i+1][1]  + distance);
        }

        int ans = 0;

        for(int i=1; i<m;i++){
            int x1 = restrictions[i-1][0];
            int h1 = restrictions[i-1][1]; 
            
            int x2 = restrictions[i][0];
            int h2 = restrictions[i][1]; 
        
            int d = x2 - x1;

            ans = max(ans, (h1 + h2 + d)/2);
        }

        ans = max(ans, (restrictions.back()[1] + (n - restrictions.back()[0])));

        return ans;
    }
};