#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool bipartite_test() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    bool seen[n];
    int color[n];
    // init graph
    for (int i = 0; i < n; i++) {
        seen[i] = false;
        adj[i].clear();
        color[n] = -1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // bfs here
    queue<int> q;
    q.push(0);
    seen[0] = true;
    color[0] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int current_color = color[u];
        for (int node : adj[u]) {
            if (seen[node] && color[node] == current_color) {
                return false;
            }
            if (!seen[node]) {
                seen[node] = true;
                color[node] = 1 - current_color;

                q.push(node);
            }
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        cout << (bipartite_test() ? "yes" : "no") << endl;
    }
    return 0;
}