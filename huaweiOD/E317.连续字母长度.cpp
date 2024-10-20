#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    string str;
    int k;
    cin >> str >> k;
    int n = str.length();
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<char,int> cnt;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        char c = str[i];
        ++len;
        if (i == n-1 || str[i+1] != c) {
            cnt[c] = max(cnt[c], len);
            len = 0;
        }
    }
    for (auto it : cnt) {
        pq.push(it.second);
        if (pq.size() > k) pq.pop();
    }
    cout << (pq.size() == k ? pq.top() : -1) << endl;
}