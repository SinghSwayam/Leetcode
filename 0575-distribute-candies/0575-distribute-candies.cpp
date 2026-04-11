class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int totalCandies = candyType.size();

        unordered_set<int> uniqueCandies;
        for(int candy : candyType){
            uniqueCandies.insert(candy);
        }

        int ans = uniqueCandies.size();

        return ans > totalCandies/2 ? totalCandies/2 : ans;
    }
};