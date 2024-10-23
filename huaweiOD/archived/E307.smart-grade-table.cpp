#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Student {
public:
    string name;
    int totalScore;
    map<string,int> scores;

    Student(const string& name): name(name), totalScore(0) {}

    void addScore(const string& subject, int score) {
        scores[subject] = score;
        totalScore += score;
    }

    int getScore(const string& subject) const {
        auto it = scores.find(subject);
        return it != scores.end() ? it->second : totalScore;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> subjects(m);
    for (int i = 0; i < m; ++i) {
        cin >> subjects[i];
    }
    vector<Student> students;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        Student student(name);
        for (int j = 0; j < m; ++j) {
            int score;
            cin >> score;
            student.addScore(subjects[j], score);
        }
        students.push_back(student);
    }
    string rankSubject;
    cin >> rankSubject;
    sort(students.begin(), students.end(), [&](const Student& a, const Student& b) {
        int scoreA = a.getScore(rankSubject);
        int scoreB = b.getScore(rankSubject);
        if (scoreA != scoreB) {
            return scoreA > scoreB;
        }
        return a.name < b.name;
    });

    for (const auto& student : students) {
        cout << student.name << " ";
    }
    cout << endl;
}