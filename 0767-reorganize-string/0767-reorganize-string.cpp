class Solution {
public:
    string reorganizeString(string s) {
        // greedy approach
        vector<int> hash(26,0);

        for(int i=0;i<s.size();i++){
            hash[s[i] - 'a']++;
        }

        // find the most frequent character
        char most_freqent_char;
        int max_freq=INT_MIN;

        for(int i=0;i<26;i++){
            if(hash[i] > max_freq){
                max_freq = hash[i];
                most_freqent_char = i + 'a';
            }
        }

        // placing most frequent char
        int index = 0;
        while(max_freq>0 && index<s.size()){
            s[index] = most_freqent_char;
            max_freq--;
            index+=2;
        }

        if(max_freq != 0){
            return "";
        }

        hash[most_freqent_char-'a'] = 0;

        // place remaining characters
        for(int i=0;i<26;i++){
            while(hash[i]>0){
                index = index >= s.size() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index+=2;
            }
        }

        return s;
    }
};