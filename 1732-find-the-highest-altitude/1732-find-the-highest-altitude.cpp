class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int largestAlt = 0;
        int currLargest = 0;
        for(int num : gain){
            currLargest += num;
            largestAlt = max(largestAlt,currLargest);
        }
        return largestAlt;
    }
};