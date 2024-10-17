#include "abel_macro.h"

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int cnt[4001] = {0};
        int *hash_set = cnt + 2000;
        for (int n : arr) ++hash_set[n];
        for (int n : arr) {
            if (n != 0 && hash_set[2*n] > 0) return true;
            else if (n == 0 && hash_set[2*n] > 1) return true;
        }
        return false;
    }
};