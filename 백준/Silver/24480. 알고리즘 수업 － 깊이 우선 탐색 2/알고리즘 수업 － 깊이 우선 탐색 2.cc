#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

static int n, m, r, seq=0;
static vector< vector <int>> v;
static vector<bool> visited;
static stack<int> s;

static vector<int> order;

void DFS(int n);

bool compare(int i, int j) {
	return j < i;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> r;
	v.resize(n + 1);
	order.resize(n + 1);
	v.resize(n + 1);
	visited = vector<bool>(n + 1, false);
	int node1, node2;
	for (int i = 1; i <= m; i++) {
		cin >> node1 >> node2;
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end(), compare);
	}
	DFS(r);

	for (int i = 1; i <= n; i++) {
		cout << order[i] << "\n";
	}
}

void DFS(int n) {
	seq++;
	order[n] = seq;
	visited[n] = true;
	for (int i : v[n]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}