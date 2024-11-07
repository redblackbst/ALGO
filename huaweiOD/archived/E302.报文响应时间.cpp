#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arrivalTime[n];
    int maxRespCode[n];

    for (int i = 0; i < n; ++i) {
        cin >> arrivalTime[i];
        cin >> maxRespCode[i];
    }

    int minRespTime = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int maxRespTime = 0;
        if (maxRespCode[i] < 128) {
            maxRespTime = maxRespCode[i];
        } else {
            int exp = (maxRespCode[i] & 0x70) >> 4;
            int mant = maxRespCode[i] & 0x0F;
            maxRespTime = (mant | 0x10) << (exp + 3);
        }
        int responseTime = arrivalTime[i] + maxRespTime;
        minRespTime = min(minRespTime, responseTime);
    }
    cout << minRespTime << endl;
}