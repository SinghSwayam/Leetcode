class Info{
    public:
    int data;
    int row;
    int col;

    Info(int data, int row, int col){
        this->data = data;
        this->col = col;
        this->row = row;
    }
};

class Compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, Compare> minheap;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        int k = nums.size();

        for(int i=0;i<k;i++){
            Info* temp = new Info(nums[i][0], i, 0);
            minheap.push(temp);
            maxi = max(maxi, nums[i][0]);
        }

        int start = minheap.top()->data;
        int end = maxi; 

        while(!minheap.empty()){
            Info* frontInfo = minheap.top();
            minheap.pop();

            mini = frontInfo->data;
            int curRow = frontInfo->row;
            int curCol = frontInfo->col;

            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }

            if(curCol + 1 < nums[curRow].size()){
                maxi = max(maxi, nums[curRow][curCol + 1]);
                Info* newInfo = new Info(nums[curRow][curCol + 1], curRow, curCol+1);
                minheap.push(newInfo);
            }else{
                break;
            }
        }

        return {start, end};
    }
};

// Time complexity : O(N log K) where N is total number of elements and K is the number of lists