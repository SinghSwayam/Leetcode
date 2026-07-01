class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxheap;
        if(a > 0)maxheap.push({a, 'a'});
        if(b > 0)maxheap.push({b, 'b'});
        if(c > 0)maxheap.push({c, 'c'});

        string ans = "";

        while(maxheap.size() > 1){
            auto [freq_1, ch_1] = maxheap.top(); maxheap.pop();
            auto [freq_2, ch_2] = maxheap.top(); maxheap.pop();

            if(freq_1 > 2){
                ans += ch_1;
                ans += ch_1;
                freq_1 -= 2;
            }else{
                ans += ch_1;
                freq_1--;
            }
            
            if(freq_2 >= 2 && freq_2 >= freq_1){ // important : freq_2 >= freq_1
                ans += ch_2;
                ans += ch_2;
                freq_2 -= 2;
            }else{
                ans += ch_2;
                freq_2--;
            }

            if(freq_1 > 0){
                maxheap.push({freq_1, ch_1});
            }

            if(freq_2 > 0){
                maxheap.push({freq_2, ch_2});
            }
        }

        if(maxheap.size() == 1){
            auto [freq, ch] = maxheap.top(); maxheap.pop();
            if(freq >= 2){
                ans += ch;
                ans += ch;
            }else{
                ans += ch;
            }
        }
        return ans;
    }
};