#include <iostream>
using namespace std;

int main() {
    string line;
    cin >> line;
    int num = 0;
    for (char c : line) {
        int d = c - '0';
        if (d > 4) {
            --d;
        }
        num = 9 * num + d;
    }
    cout << num << endl;
}