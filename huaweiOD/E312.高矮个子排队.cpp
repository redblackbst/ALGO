#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    if (str.find_first_not_of("0123456789 ") != string::npos) {
        cout << "[]" << endl;
        return 0;
    }
    istringstream iss(str);
    vector<int> heights;
    int h;
    while (iss >> h) {
        heights.push_back(h);
    }
    int n = heights.size();
    for (int i = 0, j = 1; j < n; ++i, ++j) {
        if (heights[i] != heights[j] && (heights[i] > heights[j]) != (i % 2 == 0)) {
            swap(heights[i], heights[j]);
        }
    }
    for (int i = 0; i < n-1; ++i) {
        cout << heights[i] << " ";
    }
    cout << heights[n-1];
}