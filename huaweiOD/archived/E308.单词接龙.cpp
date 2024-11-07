#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

struct cmp {
    bool operator() (const string& a, const string& b) const {
        const size_t m = a.length(), n = b.length();
        return (m == n) ? (a < b) : (m > n);
    }
};

int main() {
    int idx, n;
    cin >> idx >> n;
    unordered_map<char,set<string,cmp>> dict;
    string res;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        if (i == idx) {
            res = word;
        } else {
            dict[word[0]].insert(word);
        }
    }
    while (true) {
        char &c = res.back();
        if (dict[c].empty()) break;
        auto it = dict[c].begin();
        res += *it;
        dict[c].erase(it);
    }
    cout << res << endl;
}
