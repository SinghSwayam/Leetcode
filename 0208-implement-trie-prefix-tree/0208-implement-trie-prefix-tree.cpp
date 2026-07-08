class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;

    void insertWord(TrieNode* root, const string &word, int pos){
        if(pos == word.size()){
            root->isTerminal = true;
            return;
        }

        int index = word[pos] - 'a';

        if(root->children[index] == NULL)
            root->children[index] = new TrieNode(word[pos]);

        insertWord(root->children[index], word, pos + 1);
    }

    bool searchWord(TrieNode* root, string word, int pos){
        // base case
        if(pos == word.length()){
            return root->isTerminal;
        }

        int index = word[pos] - 'a';

        if(root->children[index] == NULL){
            return false;
        }

        return searchWord(root->children[index], word, pos + 1);
    }

    bool startsWithWord(TrieNode* root, const string &prefix, int pos) {
        if(pos == prefix.length()) return true;

        int index = prefix[pos] - 'a';

        if (root->children[index] == NULL) {
            return false;
        }

        return startsWithWord(root->children[index], prefix, pos + 1);
    }

public:
    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        insertWord(root, word, 0);
    }
    
    bool search(string word) {
        return searchWord(root, word, 0);
    }
    
    bool startsWith(string prefix) {
        return startsWithWord(root, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */