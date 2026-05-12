class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[1] - a[0] > b[1] - b[0];
    }

    bool canComplete(vector<vector<int>>& tasks, int minEnergy){
        for(int i=0; i<tasks.size(); i++){
            if(minEnergy < tasks[i][1]){
                return false;
            }
            
            minEnergy -= tasks[i][0];
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp);
        int s=1;
        int e=0;
        for(int i=0;i<tasks.size();i++){
            e += tasks[i][1];
        }

        while(s<=e){
            int mid = s + (e-s) / 2;
            if(canComplete(tasks,mid)){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return s;

    }
};