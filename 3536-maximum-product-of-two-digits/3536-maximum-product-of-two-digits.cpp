class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;
        while(n){
            int d = n % 10;
            pq.push(d);
            n /= 10;
        }
        
        int f = pq.top(); pq.pop();
        int s = pq.top(); pq.pop();

        return f*s;

    }
};