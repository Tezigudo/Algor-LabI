#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

bool canGo(int height[], int from, int to, int p) {
    return height[to] <= height[from] + p || height[from] >= height[to];
}

bool can_travel(int height[], vector<int> adj[], int from, int to, int p,
                int n) {
    queue<int> q;
    bool seen[n];
    memset(seen, false, n);

    q.push(from);
    seen[from] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!seen[v]) {
                if (v == to && canGo(height, u, v, p)) {
                    return true;
                }

                if (canGo(height, u, v, p)) {
                    seen[v] = true;
                    q.push(v);
                }
            }
        }
    }

    return false;
}
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    int height[n];
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int j = 0; j < q; j++) {
        int from, to, p;
        cin >> from >> to >> p;
        from--;
        to--;
        if (can_travel(height, adj, from, to, p, n)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
