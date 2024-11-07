#include "../utils/abel_macro.h"
#include <iterator>

int main() {
    string ops;
    cin >> ops;
    vector<int> S{0,1,2,3,4,5,6};
    auto rotate = [&](int a, int b, int c, int d) {
        int tmp = S[a];
        S[a] = S[b];
        S[b] = S[c];
        S[c] = S[d];
        S[d] = tmp;
    };
    auto turnL = [&]() {rotate(1, 5, 2, 6);};
    auto turnR = [&]() {rotate(1, 6, 2, 5);};
    auto turnF = [&]() {rotate(3, 5, 4, 6);};
    auto turnB = [&]() {rotate(3, 6, 4, 5);};
    auto turnA = [&]() {rotate(1, 4, 2, 3);};
    auto turnC = [&]() {rotate(1, 3, 2, 4);};
    for (char c : ops) {
        if (c == 'L') turnL();
        else if (c == 'R') turnR();
        else if (c == 'F') turnF();
        else if (c == 'B') turnB();
        else if (c == 'A') turnA();
        else if (c == 'C') turnC();
    }
    copy(S.begin() + 1, S.end(), ostream_iterator<int>(cout));
}