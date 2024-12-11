#include "../utils/abel_macro.h"

class UnionFind {
public:
    vector<int> root, rank;

    UnionFind(int n) : root(n), rank(n) {
        ranges::iota(root, 0);
    }

    int find(int x) {
        if (x != root[x]) {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            root[rx] = ry;
        } else if (rank[ry] < rank[rx]) {
            root[ry] = rx;
        } else {
            root[rx] = ry;
            rank[ry]++;
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};


class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        unordered_map<string, int> dict;
        UnionFind uf(2 * similarPairs.size());
        int index = 0;
        for (auto& p : similarPairs) {
            string &word1 = p[0], &word2 = p[1];
            if (!dict.contains(word1)) dict[word1] = index++;
            if (!dict.contains(word2)) dict[word2] = index++;
            uf.unite(dict[word1], dict[word2]);
        }
        for (int i = 0; i < sentence1.size(); i++) {
            string &w1 = sentence1[i], &w2 = sentence2[i];
            if (w1 == w2) continue;
            if (!dict.contains(w1) || !dict.contains(w2) || !uf.isConnected(dict[w1], dict[w2])) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution a;
    vector<string> s1{"great","acting","skills"};
    vector<string> s2{"fine","drama","talent"};
    vector<vector<string>> sp{{"great","good"},{"fine","good"},{"drama","acting"},{"skills","talent"}};
    a.areSentencesSimilarTwo(s1, s2, sp);
}