#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int len, n;
    cin >> len >> n;
    int cnt = 0;
    vector<deque<int>> v(n);
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        istringstream iss(line);
        int k;
        while (iss >> k) {
            v[i].push_back(k);
            iss.ignore();
            ++cnt;
        }
    }
    vector<int> res;
    int m = 0;
    while (m < cnt) {   // roll + erase
        for (int i = 0; i < n ; ++i) {
            auto t = len > v[i].size() ? v[i].end() : v[i].begin()+len;
            copy(v[i].begin(), t, back_inserter(res));
            v[i].erase(v[i].begin(), t);
            ++m;
        }
    }
    copy(res.begin(), res.end() - 1, ostream_iterator<int>(cout, ","));
    cout << res.back() << endl;
}