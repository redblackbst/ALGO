#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int findBestSeat(vector<int>& v, int N) {
    if (v.empty()) return 0;
    if (v.size() == 1) return N-1;
    int idx = -1, dist = 0;
    if (v.front() > 0) {
        dist = v.front();
        idx = 0;
    }
    if (N - 1 - v.back() > dist) {
        dist = N - 1 - v.back();
        idx = N - 1;
    }
    for (int i = 1; i < v.size(); ++i) {
        int d = (v[i] - v[i-1]) / 2;
        if (d > dist) {
            dist = d;
            idx = v[i-1] + d;
        }
    }
    return idx;
}

int main() {
    int N;
    cin >> N; cin.ignore();
    string line;
    getline(cin, line);
    line = line.substr(1, line.length()-2);
    stringstream ss(line);
    vector<int> seats;
    int k, seat = -1;
    while (ss >> k) {
        ss.ignore();
        if (k == 1) {
            seat = findBestSeat(seats, N);
            if (seat == -1) continue;
            if (seats.empty()) {
                seats.push_back(seat);
                continue;
            }
            auto it = find_if(seats.begin(), seats.end(), [&seat](const int idx) {return idx < seat;});
            seats.insert(it + 1, seat);
        } else if (k < 0) {
            k = -k;
            auto it = find(seats.begin(), seats.end(), k);
            if (it != seats.end()) seats.erase(it);
        }
    }
    cout << seat << endl;
}