#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> point;

bool isVaild(point p, int d){
    return p.second <= d && p.second >= -d;
}

bool isLeft(point p1, point p2, int d){
    return p1.first - p2.first == d;
}

bool isInRange(point p1, point p2, int d){
    return abs(p1.first - p2.first) <= d;
}

int radarCount(vector<point> points, int d){
    int count = 0;
    for (int i = 0; i < points.size(); i++) {
        if (isVaild(points[i], d)) {
            count++;
            continue;
        }
        for (int j = i + 1; j < points.size(); j++) {
            if (isLeft(points[i], points[j], d)) {
                count++;
                break;
            }
            if (isInRange(points[i], points[j], d)) {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    int n, d, caseNum = 1;
    while (cin >> n >> d && !(n == 0 && d == 0)) {
        int ans = -1;
        vector<point> points;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }

        sort(points.begin(), points.end());
        string blankline;
        getline(cin, blankline);

        // cout << "Case " << caseNum++ << ": " << count << endl;;
    }
    return 0;
}