#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    unordered_map<string,int> cardVal = {
        {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7},
        {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12},
        {"K", 13}, {"A", 14}, {"2", 16}
    };

    string card;
    vector<string> hands;
    while (cin >> card) {
        hands.push_back(card);
    }
    sort(hands.begin(), hands.end(), [&cardVal](const string& a, const string& b) {
        return cardVal[a] < cardVal[b];
    });

    vector<vector<string>> allStraights;
    allStraights.push_back(vector<string>(1, hands[0]));
    for (int i = 1; i < hands.size(); ++i) {
        bool added = false;
        for (auto& straight : allStraights) {
            if (cardVal[hands[i]] - cardVal[straight.back()] == 1) {
                straight.push_back(hands[i]);
                added = true;
                break;
            }
        }
        if (!added) {
            allStraights.push_back(vector<string>(1, hands[i]));
        }
    }
    bool hasValid = false;
    for (const auto& straight : allStraights) {
        if (straight.size() >= 5) {
            hasValid = true;
            for (const auto& card : straight) {
                cout << card << " ";
            }
            cout << endl;
        }
    }
    if (!hasValid) {
        cout << "No" << endl;
    }
}