#include "../utils/abel_macro.h"

class Trie {
private:
    vector<Trie*> next;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this; 
        for (char c : prefix) {
            if (node->next[c-'a'] == nullptr) {
                return nullptr;
            }
            node = node->next[c-'a'];
        }
        return node;
    }

public:
    Trie() : next(26), isEnd(false) {}
    
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c-'a'] == nullptr) {
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */