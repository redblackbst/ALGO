#include "../utils/abel_macro.h"
#include <iterator>

class Trie {
private:
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
    vector<Trie*> next;
    bool isEnd;
    Trie() : next(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c-'a'] == nullptr) {
                node->next[c-'a'] = new Trie;
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }

    bool search(const string& word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(const string& prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

int main() {
    string str;
    getline(cin, str);
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    Trie* trie = new Trie();
    string dict;
    getline(cin, dict);
    stringstream ss(dict);
    string s;
    while (getline(ss, s, ',')) {
        trie->insert(s);
    }

    vector<string> res;
    int i = 0, n = str.size();
    while (i < n) {
        if (!isalpha(str[i])) {
            // res.push_back(str.substr(i, 1));
            i++;
            continue;
        }
        auto idx = str.find_first_of(',', i);
        int j = idx == string::npos ? n : idx;
        while (j > i) {
            if (trie->search(str.substr(i, j - i))) {
                break;
            }
            j--;
        }
        if (j == i) {
            res.push_back(str.substr(i, 1));
            i++;
        } else {
            res.push_back(str.substr(i, j - i));
            i = j;
        }
    }
    copy(res.begin(), res.end(), ostream_iterator<string>(cout, ","));
}