#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    bool operator < (const Point& b) {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
};

bool operator==(const Point& a, const Point& b) {
    return a.x == b.x && b.y == b.y;
}

bool bs(vector<Point>& points, Point p, int l, int r) {
    int left = l, right = r, mid;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (points[mid] == p) return true;
        if (points[mid] < p) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());

    int cnt = 0;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
        x1 = points[i].x;
        y1 = points[i].y;
        for (int j = i+1; j < n; ++j) {
            x2 = points[j].x;
            y2 = points[j].y;

            Point p3 = {x1 - (y1 - y2), y1 + (x1 - x2)};
            Point p4 = {x2 - (y1 - y2), y2 + (x1 - x2)};

            if (bs(points, p3, j+1, n-1) && bs(points, p4, j+1, n-1)) {
                ++cnt;
            }

            Point p5 = {x1 + (y1 - y2), y1 - (x1 - x2)};
            Point p6 = {x2 + (y1 - y2), y2 - (x1 - x2)};

            if (bs(points, p5, j+1, n-1) && bs(points, p6, j+1, n-1)) {
                ++cnt;
            }
        }
    }
    cout << cnt / 4 << endl;
}
