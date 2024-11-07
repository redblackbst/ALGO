#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    vector<int> nums;
    stringstream ss(line1);
    string token;
    while (getline(ss, token, ',')) {
        nums.push_back(stoi(token));
    }

    int target = stoi(line2);
    int n = nums.size();
    int sum = 0, maxlen = -1;

    for (int i = 0, j = 0; j < n; ++j) {
        sum += nums[j];
        while (sum > target && i < j) {
            sum -= nums[i];
            ++i;
        }
        if (sum == target) {
            maxlen = max(maxlen, j-i+1);
        }
    }
    cout << maxlen << endl;
}