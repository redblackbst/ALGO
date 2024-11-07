#include "../utils/abel_macro.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = -1, right = m * n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int x = matrix[mid/n][mid%n];   // not m
            if (x == target) return true;
            (x < target ? left : right) = mid;
        }
        return false;
    }
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};