#include "../utils/abel_macro.h"

int main() {
    long long X, Y, Z;
    cin >> X >> Y;
    Z = max(1LL, static_cast<long long>(ceil(log10(X / pow(26, Y)))));
    cout << Z << endl;
}