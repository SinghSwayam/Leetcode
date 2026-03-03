class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber){
            columnNumber--;
            char c = columnNumber%26 + 'A';
            columnNumber /= 26;
            s.push_back(c);
        }

        reverse(s.begin(),s.end());

        return s;
    }
};