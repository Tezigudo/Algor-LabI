#include<cstdio>
#include<vector>
#include <iostream>

using namespace std;

int T, N, a, b;
vector<int> graph, s;
vector<bool> vis;

int dfs(int u) {
	vis[u] = true;
	int tot = 0;
	if(graph[u] != -1 && !vis[graph[u]])
		tot += 1 + dfs(graph[u]);
	vis[u] = false;
	return s[u] = tot;
}

int main() {
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> N;
		graph.assign(N, -1);
		s.assign(N, -1);
		vis.assign(N, false);
		for(int i = 0; i < N; i++) {
			cin >> a >> b;
			graph[a - 1] = b - 1;
		}
		int ans = 0, best_len = 0;
		for(int i = 0; i < N; i++) {
			if(s[i] == -1) dfs(i);
			if(s[i] > best_len) {
				best_len = s[i];
				ans = i;
			}
		}
        cout << "Case " << t << ": " << ans+1 << endl;
	}
}
