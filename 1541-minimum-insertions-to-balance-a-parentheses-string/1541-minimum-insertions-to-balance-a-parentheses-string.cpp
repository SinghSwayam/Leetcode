class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int insertions = 0;
        int open = 0;

        for(int i=0;i < n; i++){
            if(s[i] == '('){
                open++;
            }else{
                if(i+1 < n && s[i+1] == ')'){
                    i++;
                }else{
                    insertions++;
                }
                
                if(open > 0){
                    open--;
                }else{
                    insertions++;
                }
            }
        }

        insertions += open*2;
        return insertions;
    }
};