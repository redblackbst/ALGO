#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size(), cnt = 0;
    for (char c : s) {
        if (c == 'o') ++cnt;
    }
    if (cnt % 2 == 0) {
        cout << len << endl;
    } else {
        cout << len - 1 << endl;
    }
}