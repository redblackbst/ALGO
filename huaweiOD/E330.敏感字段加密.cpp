#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    int k;
    string str;
    cin >> k >> str;
    vector<string> wordList;
    bool inQuote = false;
    for (int i = 0, j = 0; j < str.length(); ++j) {
        char c = str[j];
        if (c == '"') {
            if (inQuote) {
                wordList.push_back(str.substr(i, j-i+1));
                inQuote = false;
                i = j + 1;
            } else {
                i = j;
                inQuote = true;
            }
        } else if (c == '_' && !inQuote) {
            if (i != j) {
                wordList.push_back(str.substr(i, j-i));
                i = j + 1;
            } else {
                i += 1;
            }
        } else if (j == str.length() - 1) {
            wordList.push_back(str.substr(i, j-i+1));
        }
    }
    if (k < 0 || k > wordList.size() - 1) {
        cout << "ERROR" <<  endl;
    } else {
        wordList[k] = "******";
        copy(wordList.begin(), wordList.end() - 1, ostream_iterator<string>(cout, "_"));
        cout << wordList.back();
    }
}