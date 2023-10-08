// 13023

#include <iostream>
#include <vector>

using namespace std;

static vector< vector<int> > v;
static vector<bool> visited;
static bool arrive;

void DFS(int now, int depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	arrive = false;
	v.resize(n);
	visited = vector<bool>(n, false);

	int a, b;
	while(m--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		DFS(i, 1);
		if (arrive)break;
	}

	if (arrive) {
		cout << 1;
		return 0;
	}

	cout << 0;
	return 0;
}

void DFS(int now, int depth) {
	if (depth == 5 || arrive) {
		arrive = true;
		return;
	}

	visited[now] = true;

	for (int i : v[now]) {
		if (!visited[i]) {
			DFS(i, depth + 1);
		}
	}

	visited[now] = false;
}