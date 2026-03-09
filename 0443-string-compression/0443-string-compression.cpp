class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = chars[0];
        int index = 0, count = 1;

        for (int i = 1; i < chars.size(); i++) {
            if (prev == chars[i]) {
                count++;
            } else {
                chars[index] = prev;
                index++;
                if (count > 1) {
                    int start = index;
                    while (count) {
                        chars[index] = (count % 10 ) + '0';
                        index++;
                        count /= 10;
                    }
                    reverse((chars.begin() + start) ,(chars.begin() + index) );
                }
                prev = chars[i];
                count = 1;
            }
        }
        
        chars[index] = prev;
        index++;
        if (count > 1) {
            int start = index;
            while (count) {
                chars[index] = (count % 10 + '0');
                index++;
                count /= 10;
            }
            reverse((chars.begin() + start) ,(chars.begin() + index) );
        }

        return index;
    }
};