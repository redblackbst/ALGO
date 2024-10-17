#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> readIntArray(int m) {
    vector<int> nums(m);
    for (int i = 0; i < m; ++i) {
        cin >> nums[i];
    }
    return nums;
}

int main() {
    int m, N, X;
    cin >> m >> N >> X;
    vector<int> returns = readIntArray(m);
    vector<int> risks = readIntArray(m);
    vector<int> investLimits = readIntArray(m);
    int maxReturn = 0;
    vector<int> bestInvestments(m, 0);

    for (int i = 0; i < m; ++i) {
        if (risks[i] <= X) {
            int investment = min(N, investLimits[i]);
            int curReturn = investment * returns[i];
            if (curReturn > maxReturn) {
                maxReturn = curReturn;
                fill(bestInvestments.begin(), bestInvestments.end(), 0);
                bestInvestments[i] = investment;
            }
        }
        for (int j = i + 1; j < m; ++j) {
            if (risks[i] + risks[j] <= X) {
                int investment1, investment2;
                if (returns[i] > returns[j]) {
                    investment1 = min(N, investLimits[i]);
                    investment2 = min(N - investment1, investLimits[j]);
                } else {
                    investment2 = min(N, investLimits[j]);
                    investment1 = min(N - investment2, investLimits[i]);
                }
                int curReturn = investment1 * returns[i] + investment2 * returns[j];
                if (curReturn > maxReturn) {
                    maxReturn = curReturn;
                    fill(bestInvestments.begin(), bestInvestments.end(), 0);
                    bestInvestments[i] = investment1;
                    bestInvestments[j] = investment2;
                }
            }
        }
    }
    for (int investment : bestInvestments) {
        cout << investment << " ";
    }
    cout << endl;
}