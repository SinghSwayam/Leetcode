class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int pile : piles){
            pq.push(pile);
        }

        while(k--){
            int temp = pq.top();
            pq.pop();

            int newPile = temp - floor(temp/2);
            pq.push(newPile);
        }

        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};