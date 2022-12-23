#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    map<int, vector<vector<int> > > m;
    int n;
    cin >> n;
    map<int, int> max_diff;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if (m.find(h) == m.end()) {
            m[h] = vector<vector<int> >();
            vector<int> v;
            v.push_back(i);
            m[h].push_back(v);
        } else {
            vector<int> v = m[h].back();
            if (v.size() == 2) {
                vector<int> vv;
                vv.push_back(i);
                m[h].push_back(vv);
                if (max_diff.find(h) == max_diff.end()) {
                    max_diff[h] = v[1] - v[0];
                } else {
                    max_diff[h] = max(max_diff[h], v[1] - v[0]);
                }
            } else {
                v.push_back(i);
                if (v.size() == 1) {
                    m[h].pop_back();
                    m[h].push_back(v);
                } else {
                    m[h].push_back(v);
                }
            }
        }
    }
    if (max_diff.empty()) {
        cout << -1 << endl;
    } else {
        int max = 0;
        for (auto it = max_diff.begin(); it != max_diff.end(); it++) {
            if (it->second > max) {
                max = it->second;
            }
        }
        cout << max << endl;
    }
    return 0;
}
