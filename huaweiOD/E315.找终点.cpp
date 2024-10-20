#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums;
    int k;
    while (cin >> k) {
        nums.push_back(k);
    }
    int n = nums.size(), minStep = INT_MAX;
    for (int i = 0; i < n/2; ++i) {
        int step = 1;
        int idx = i;
        while (idx < n-1) {
            idx += nums[i];
            ++step;
        }
        if (idx == n-1) minStep = min(minStep, step);
    }
    cout << (minStep == INT_MAX ? -1 : minStep) << endl;
}