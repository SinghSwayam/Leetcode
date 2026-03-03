class Solution {
public:
    void removeOccRecursive(string&s, string&part){
        
        int found = s.find(part);
        if(found != string::npos){     
            s.erase(found, part.size());
            removeOccRecursive(s,part);
        }else{
            //base case : all Occurances has been removed 
            return;
        }

    }

    string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        while(pos != string::npos){
            s.erase(pos,part.length());
            pos = s.find(part);
        }

        return s;
    }
};