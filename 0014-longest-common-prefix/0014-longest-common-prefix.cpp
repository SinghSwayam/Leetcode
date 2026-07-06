class TrieNode { 
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount = 0;

    TrieNode(char d){
        this->data = d;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        childCount = 0;
        this->isTerminal = false;
    }
};

class Solution {
    void insertWord(TrieNode* root, const string &word, int pos){
        if(pos == word.size()){
            root->isTerminal = true;
            return;
        }

        int index = word[pos] - 'a';

        if(root->children[index] == NULL){
            root->children[index] = new TrieNode(word[pos]);
            root->childCount++;
        }

        insertWord(root->children[index], word, pos + 1);
    }

    void findLCP(TrieNode* root, string first, string& ans){
        if(root->isTerminal) return;

        for(int i=0; i< first.length(); i++){
            char ch = first[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }else{
                break;
            }

            if(root->isTerminal)
                break;
        }
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        for(string str : strs){
            insertWord(root,str,0);
        }

        string ans = "";
        string first = strs[0];

        findLCP(root, first, ans);
        
        return ans;
    }
};