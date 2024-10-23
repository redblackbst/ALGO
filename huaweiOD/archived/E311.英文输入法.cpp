#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    string str, pre, word;
    getline(cin, str);
    getline(cin, pre);
    replace_if(str.begin(), str.end(), [](char c) {return !isalpha(c);}, ' ');
    stringstream ss(str);
    set<string> dict;
    while (ss >> word) {
        dict.insert(word);
    }
    string ans;
    for (auto s : dict) {
        if (s.substr(0, pre.length()) == pre) {
            ans += s + " ";
        }
    }
    cout << (ans.length() ? ans : pre) << endl;
}