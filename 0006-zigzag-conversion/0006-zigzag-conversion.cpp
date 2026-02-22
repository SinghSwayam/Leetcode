class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() <= numRows) return s;

        vector<string> rows(numRows);
        bool goingDown = false;
        int currentRow = 0;

        for(char c : s){
            rows[currentRow] += c;

            if(currentRow == 0 || currentRow == numRows-1 ){
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        string result = "";

        for(string element : rows){
            result += element;
        }
        return result;
    }
};