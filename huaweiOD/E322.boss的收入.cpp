#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

unordered_map<int,long long> income;
unordered_map<int,vector<int>> parentToChildren;

void calcIncome(int parentID) {
    for (int childID : parentToChildren[parentID]) {
        calcIncome(childID);
        income[parentID] += income[childID] / 100 * 15;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    unordered_set<int> ID;
    unordered_set<int> ID1;
    for (int i = 0; i < n; ++i) {
        int childID, parentID;
        long long childIncome;
        cin >> childID >> parentID >> childIncome;
        income[childID] = childIncome;
        ID1.insert(childID);
        ID.insert(childID);
        ID.insert(parentID);

        parentToChildren[parentID].push_back(childID);
    }
    for (int i : ID) {
        if (!ID1.contains(i)) {
            calcIncome(i);
            cout << i << " " << income[i] << endl;
            break;
        }
    }
}