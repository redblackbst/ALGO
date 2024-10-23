#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;
    int cnt = 0;

    for (long long i = x; i > 1; i /= 2, ++cnt) {
        if (i == 3) {
            cnt += 2;
            break;
        }
        if (i % 2 != 0) {
            if ((i + 1) / 2 % 2 == 0) {
                ++i;
            } else {
                --i;
            }
            ++cnt;
        }
    }
    cout << cnt << endl;
}