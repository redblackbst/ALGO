#include <iostream>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    int x, last_x = 0, offset_y, y = 0;
    long long f = 0;
    cin >> last_x >> y;
    for (int i = 1; i < n; ++i) {
        cin >> x >> offset_y;
        f += abs(y) * (x - last_x);
        y += offset_y;
        last_x = x;
    }
    f += abs(y) * (e - last_x);
    cout << f << endl;
}