// 11438 LCA 2 (https://www.acmicpc.net/problem/11438)
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

static vector<vector<int>> tree;
static vector<bool> visited;
static vector<int> depth;
static int parent[21][100001];

static int kmax;

void BFS(int node);
int LCA(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	depth.resize(N + 1);
	tree.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	int tmp = 1;
	kmax = 0;
	while (tmp <= N) {
		tmp <<= 1;

		kmax++;
	}

	BFS(1);

	for (int k = 1; k <= kmax; k++) {
		for (int n = 1; n <= N; n++) {
			parent[k][n] = parent[k - 1][parent[k - 1][n]];
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
}

int LCA(int a, int b) {
	if (depth[a] > depth[b]) { // b가 더 깊은 쪽이 되도록 변경
		int temp = a;
		a = b;
		b = temp;
	}

	for (int k = kmax; k >= 0; k--) { // 깊이 빠르게 맞추기
		if (pow(2, k) <= depth[b] - depth[a]) {
			if (depth[a] <= depth[parent[k][b]]) {
				b = parent[k][b];
			}
		}
	}

	for (int k = kmax; k >= 0 && a != b; k--) { // 조상 빠르게 맞추기
		if (parent[k][a] != parent[k][b]) {
			a = parent[k][a];
			b = parent[k][b];
		}
	}

	int LCA = a;

	if (a != b) {
		LCA = parent[0][LCA];
	}

	return LCA;
}

void BFS(int node) {
	queue<int> que;
	que.push(node);
	visited[node] = true;

	int level = 1;
	int now_size = 1;
	int count = 0;

	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int next : tree[now]) {
			if (!visited[next]) {
				que.push(next);
				visited[next] = true;
				depth[next] = level;
				parent[0][next] = now;
			}
		}

		count++;
		if (count == now_size) {
			count = 0;
			now_size = que.size();
			level++;
		}
	}
}