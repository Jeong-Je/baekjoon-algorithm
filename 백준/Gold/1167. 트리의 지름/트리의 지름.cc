#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector< vector<pair<int, int> >> A;
static vector<bool> visited;
static vector<int> m_distance;

void BFS(int node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	A.resize(n + 1);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		while (true) {
			int e, weight;
			cin >> e;
			if (e == -1)break;
			cin >> weight;
			A[num].push_back(make_pair(e, weight));
		}
	}

	m_distance = vector<int>(n + 1, 0);
	visited = vector<bool>(n + 1, false);

	BFS(1);

	int max = 1;

	for (int i = 2; i <= n; i++) {
		if (m_distance[max] < m_distance[i])max = i;
	}

	fill(m_distance.begin(), m_distance.end(), 0);
	fill(visited.begin(), visited.end(), false);

	BFS(max);

	sort(m_distance.begin(), m_distance.end());

	cout << m_distance.at(n);


	return 0;
}


void BFS(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (pair<int, int> i : A.at(now)) {
			if (!visited.at(i.first)) {
				visited.at(i.first) = true;
				q.push(i.first);
				m_distance[i.first] = m_distance[now] + i.second;
			}
		}
	}
}