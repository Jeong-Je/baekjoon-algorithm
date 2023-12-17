#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> v;

bool DFS(int x, int before) {
	visited[x] = true;

	for (int i : v[x]) {
		if (i == before)continue;
		if (visited[i])return false;
		if (!DFS(i, x))return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, n1, n2, cnt=0;

	while (true) {
		int ans = 0;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		cnt++;

		visited.clear();
		visited.resize(n+1, false);

		v.clear();
		v.resize(n+1);

		for (int i = 1; i <= n; i++) {
			for (int i : v[i])
				cout << i << "\n";
		}

		for (int i = 0; i < m; i++) {
			cin >> n1 >> n2;
			v[n1].push_back(n2);
			v[n2].push_back(n1);
		}


		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				if (DFS(i, 0))ans++;
			}
		}

		cout << "Case " << cnt << ": ";
		if (ans == 0) {
			cout << "No trees.\n";
		}
		else if (ans == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << ans << " trees.\n";
		}
	}


	return 0;
}