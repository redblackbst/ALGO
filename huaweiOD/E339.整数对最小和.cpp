#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n1;
    cin >> n1;
    vector<int> a1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> a1[i];
    }
    int n2;
    cin >> n2;
    vector<int> a2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> a2[i];
    }
    int k;
    cin >> k;
    priority_queue<int> pq;
    for (int x : a1) {
        for (int y : a2) {
            pq.push(x + y);
            if (pq.size() > k) pq.pop();
        }
    }
    int sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
}