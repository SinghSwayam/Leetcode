class TrieNode { 
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        this->data = d;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('-');
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) {
                curr->children[idx] = new TrieNode(word[i]);
            }
            curr = curr->children[idx];
        }

        curr->isTerminal = true;
    }
    
    bool searchHelper(TrieNode* root, string &word, int pos) {
        if(pos == word.length()) {
            return root->isTerminal;
        }

        if(word[pos] == '.') {
            for(int i = 0; i < 26; i++) {
                if(root->children[i] != NULL) {
                    if(searchHelper(root->children[i], word, pos + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }

        int idx = word[pos] - 'a';
        if(root->children[idx] == NULL) {
            return false;
        }
        return searchHelper(root->children[idx], word, pos + 1);
    }

    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */