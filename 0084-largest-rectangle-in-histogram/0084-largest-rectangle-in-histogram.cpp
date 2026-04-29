class Solution {
public:
    vector<int> findPrevSmaller(vector<int>& arr){
        vector<int> ans(arr.size());
        stack<int> s;
        s.push(-1);

        for(int i=0;i<arr.size();i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> findNextSmaller(vector<int>& arr){
        vector<int> ans(arr.size());
        stack<int> s;
        s.push(-1);

        for(int i=arr.size()-1;i>=0;i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> prevSmall = findPrevSmaller(heights);
        vector<int> nextSmall = findNextSmaller(heights);
        int maxArea = INT_MIN;

        for(int i=0;i<size;i++){
            int l = heights[i];
            int p = prevSmall[i];
            int n = nextSmall[i] == -1 ? size : nextSmall[i];

            int area = l * (n - p - 1);
            maxArea = max(area,maxArea);
        }

        return maxArea;
    }
};