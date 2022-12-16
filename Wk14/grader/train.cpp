#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

bool bfs(vector<pair<int, int> > adj[], int level, int start, int target,
         int n) {
    // init bfs
    bool seen[n];
    memset(seen, false, n);

    list<int> Q;
    Q.push_front(start);
    seen[start] = true;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        // cout << u << endl;

        for (auto path : adj[u]) {
            int v = path.first;
            int l = path.second;
            if (!seen[v]) {
                if (v == target && level >= l) {
                    return true;
                }
                if (level >= l) {
                    seen[v] = true;
                    Q.push_front(v);
                }
            }
        }
    }

    return false;
}

int main() {
    int m, n, q;
    cin >> m >> n >> q;
    // vector<int> adj[n];
    vector<pair<int, int> > adj[n];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    for (int i = 0; i < q; i++) {
        int l, s, t;
        cin >> l >> s >> t;

        cout << (bfs(adj, l, s - 1, t - 1, n) ? "yes" : "no");

        if (i != q - 1) cout << endl;
    }
    return 0;
}