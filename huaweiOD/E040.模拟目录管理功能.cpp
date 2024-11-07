#include "../utils/abel_macro.h"

class Node {
public:
    string path;
    unordered_map<string, Node*> next;

    Node(string path, Node* parent) : path(path) {
        if (parent != nullptr) {
            this->next[".."] = parent;
        }
    }
};

bool isValidName(const string& name) {
    for (char c : name) {
        if (!islower(c)) return false;
    }
    return true;
}

int main() {
    Node* root = new Node("/", nullptr);
    Node* cur = root;
    string output;

    string input;
    while (getline(cin, input)) {
        stringstream ss(input);
        string command, arg;
        ss >> command;
        if (command == "mkdir") {
            ss >> arg;
            if (isValidName(arg) && !cur->next.contains(arg)) {
                cur->next[arg] = new Node(cur->path + arg + "/", cur);
            }
        } else if (command == "cd") {
            ss >> arg;
            if (isValidName(arg) && cur->next.contains(arg)) {
                cur = cur->next[arg];
            }
        } else if (command == "pwd") {
            output = cur->path;
        }
    }
    cout << output << endl;
}