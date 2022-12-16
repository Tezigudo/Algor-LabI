#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Tunnel {
    int to;
    int height;
};

int lowest_fee(int S, int T, int C, vector<vector<Tunnel>>& tunnels) {
    queue<pair<int, int>> q;
    q.push({S, 0});
    vector<bool> visited(tunnels.size(), false);
    while (!q.empty()) {
        int u = q.front().first;
        int fee = q.front().second;
        q.pop();
        if (u == T) {
            return fee;
        }
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (auto tunnel : tunnels[u]) {
            if (C <= tunnel.height) {
                q.push({tunnel.to, fee + 1});
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Tunnel>> tunnels(n);
    for (int i = 0; i < m; i++) {
        int a, b, h;
        cin >> a >> b >> h;
        a--;
        b--;
        tunnels[a].push_back({b, h});
        tunnels[b].push_back({a, h});
    }
    int s, t, c;
    cin >> s >> t >> c;
    cout << lowest_fee(s - 1, t - 1, c, tunnels) << endl;
    return 0;
}