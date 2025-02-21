#include "../utils/abel_macro.h"

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        ranges::sort(buses);
        ranges::sort(passengers);
        int c, j = 0;
        for (int t : buses) {
            c = capacity;
            while (c > 0 && j < passengers.size() && passengers[j] <= t) {
                c--;
                j++;
            }
        }
        j--; // now j is the last passenger aboard
        // if c > 0, the last bus must have empty seat; we sit back and relax to take the last one :)
        int ans = c ? buses.back() : passengers[j];
        while (j >= 0 && ans == passengers[j]) {
            ans--;
            j--;
        }
        return ans;
    }
};

int main() {
    auto a = Solution();
    vector<int> buses{10, 20};
    vector<int> passengers{2,17,18,19};
    int cap = 2;
    int ans = a.latestTimeCatchTheBus(buses, passengers, cap);
    cout << ans << endl;
}