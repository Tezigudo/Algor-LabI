#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int lowest_fee(vector<pair<int, int> > adj[], int s, int t, int h, int n) {
    queue<pair<int, int> > q;
    bool seen[n];
    memset(seen, false, sizeof(seen));
    q.push(make_pair(s, 0));
    seen[s] = true;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int u = p.first;
        int fee = p.second;

        seen[u] = true;
        for (auto path : adj[u]) {
            int v = path.first;
            int height = path.second;

            if (seen[v]) {
                continue;
            }
            if (v == t) {
                return fee;
            }


            if (h <= height) {
                q.push(make_pair(v, fee + 1));
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > adj[n];
    for (int i = 0; i < n; i++) {
        int a, b, h;
        cin >> a >> b >> h;
        a--;
        b--;
        adj[a].push_back(make_pair(b, h));
        adj[b].push_back(make_pair(a, h));
    }
    int s, t, c;
    cin >> s >> t >> c;
    cout << lowest_fee(adj, s - 1, t - 1, c, n) << endl;
    return 0;
}