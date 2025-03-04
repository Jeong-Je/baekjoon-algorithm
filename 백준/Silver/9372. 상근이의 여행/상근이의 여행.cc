#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int parent[1001];

void munion(int a, int b);
int find(int a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	typedef pair<int, int> route;

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;

		queue<route> q;
		for (int j = 0; j < M; j++) {
			int a, b;
			cin >> a >> b;
			q.push({ a, b });
		}

		for (int j = 1; j <= N; j++) {
			parent[j] = j;
		}

		int cnt = 0;
		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();
			int a = now.first;
			int b = now.second;

			if (find(a) != find(b)) {
				cnt++;
				munion(a, b);
			}
		}
		cout << cnt << "\n";
	}

}


void munion(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[b] = a;
	}
}
int find(int a) {
	if (a == parent[a]) return a;
	else return a = find(parent[a]);
}