class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;

        for(int i=0;i<k;i++){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }

        ans.push_back(nums[q.front()]);

        for(int i=k;i<nums.size();i++){
            if((!q.empty()) && (i - q.front() >= k)){
                q.pop_front();
            }

            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);

            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};