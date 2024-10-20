#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <iterator>
using namespace std;

int main() {
    string puzzleStr, solutionStr;
    getline(cin, puzzleStr);
    getline(cin, solutionStr);
    istringstream puzzleIss(puzzleStr), solutionIss(solutionStr);
    vector<string> puzzle, solution;
    vector<set<char>> puzzleSet, solutionSet;
    string s;
    while (puzzleIss.good()) {
        getline(puzzleIss, s, ',');
        puzzle.push_back(s);
        puzzleSet.push_back(set<char>(s.begin(), s.end()));
    }
    while (solutionIss.good()) {
        getline(solutionIss, s, ',');
        solution.push_back(s);
        solutionSet.push_back(set<char>(s.begin(), s.end()));
    }

    vector<string> res;
    for (auto& s : puzzleSet) {
        bool found = false;
        for (int i = 0; i < solutionSet.size(); ++i) {
            if (s == solutionSet[i]) {
                found = true;
                res.push_back(solution[i]);
                break;
            }
        }
        if (!found) res.push_back("not found");
    }
    copy(res.begin(), res.end()-1, ostream_iterator<string>(cout, ","));
    cout << res.back();
}