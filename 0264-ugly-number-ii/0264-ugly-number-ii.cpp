class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> minheap;
        unordered_set<long long> visited;
        minheap.push(1);
        visited.insert(1);

        long long ugly = 1;
        for(int i=0; i<n; i++){
            ugly = minheap.top();
            minheap.pop();

            long long mul2 = ugly * 2;
            long long mul3 = ugly * 3;
            long long mul5 = ugly * 5;

            if(!visited.contains(mul2)){
                minheap.push(mul2);
                visited.insert(mul2);
            }
            if(!visited.contains(mul3)){
                minheap.push(mul3);
                visited.insert(mul3);
            }
            if(!visited.contains(mul5)){
                minheap.push(mul5);
                visited.insert(mul5);
            }
        }
        return (int)ugly;
    }
};