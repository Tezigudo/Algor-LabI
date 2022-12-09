#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<pair<int, int>, int> point;

bool isValid(bool** arr, int n, int r, int c) {
    return (r >= 0) && (r < n) && (c >= 0) && (c < n) && (arr[r][c] == false);
}

int main() {
    int n, k;
    cin >> n >> k;
    queue<point> q;
    bool** arr = new bool*[10010];
    for(int i = 0; i < n; i++){
        arr[i] = new bool[10010];
        memset(arr[i], 0, 10010);
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> y >> x;
        x--;
        y--;
        arr[y][x] = 1;
        q.push(make_pair(make_pair(y, x), 0));
    }
    int level;
    while (!q.empty()) {
        point p = q.front();
        q.pop();
        int r = p.first.first;
        int c = p.first.second;
        level = p.second;

        if (isValid(arr, n, r + 1, c)) {
            arr[r + 1][c] = 1;
            q.push(make_pair(make_pair(r + 1, c), level + 1));
        }
        if (isValid(arr, n, r - 1, c)) {
            arr[r - 1][c] = 1;
            q.push(make_pair(make_pair(r - 1, c), level + 1));
        }
        if (isValid(arr, n, r, c + 1)) {
            arr[r][c + 1] = 1;
            q.push(make_pair(make_pair(r, c + 1), level + 1));
        }
        if (isValid(arr, n, r, c - 1)) {
            arr[r][c - 1] = 1;
            q.push(make_pair(make_pair(r, c - 1), level + 1));
        }
    }
    cout << level << endl;
    return 0;
}
