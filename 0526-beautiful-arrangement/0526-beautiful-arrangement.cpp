class Solution {
public:
    void solve(vector<int>& arr,int& n,int& ans,int currNum){
        if(currNum == n+1){
            ans++;
            return;
        }

        for(int i=1;i<=n;++i){
            if(arr[i] == 0 && (currNum % i == 0 || i % currNum == 0) ){
                arr[i] = currNum;
                solve(arr,n,ans,currNum+1);
                arr[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> arr(n+1);
        int ans=0;

        solve(arr,n,ans,1);

        return ans;
    }
};