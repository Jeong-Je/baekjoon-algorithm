// 11437 LCA (https://www.acmicpc.net/problem/11437)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> tree;
static vector<int> parent;
static vector<int> depth;
static vector<bool> visited;

void BFS(int node);
int LCA(int a, int b);

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);

	int N, M;
	cin >> N;

	tree.resize(N + 1);
	parent.resize(N + 1);
	depth.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	BFS(1); // 루트 노드는 항상 1이라고 전제가 됨
	
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
	
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) { // a의 깊이가 더 크도록 설정
		int temp = a;
		a = b; 
		b = temp;
	}

	while (depth[a] != depth[b]) {
		a = parent[a];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

void BFS(int node) {
	visited[node] = true;

	queue<int> que;
	que.push(node);

	int level = 1;
	int now_size = 1;
	int count = 0;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		for (int next : tree[now]) {
			if (!visited[next]) {
				visited[next] = true;
				parent[next] = now;
				depth[next] = level;
				que.push(next);
			}
		}
		count++; // 노드 하나 처리

		if (count == now_size) { // 큐에 있던 한 층을 모두 count 했으면 다음 카운트로
			level++;
			now_size = que.size();
			count = 0;
		}
	}
}