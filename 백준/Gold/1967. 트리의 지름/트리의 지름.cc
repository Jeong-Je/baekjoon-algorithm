// 1967 

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

static vector< vector<pair<int, int> >> v;
static vector<bool> visited;
static vector<int> t_distance;

void BFS(int node);

int main() {
	int n;
	cin >> n;

	v.resize(n+1);

	for (int i = 1; i < n; i++) {
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		v[node1].push_back(make_pair(node2, weight));
		v[node2].push_back(make_pair(node1, weight));
	}

	t_distance = vector<int>(n + 1, 0);
	visited = vector<bool>(n + 1, false);

	BFS(1);


	int max = 1;
	for (int i = 2; i <= n; i++) {
		if (t_distance.at(i) > t_distance.at(max)) {
			max = i;
		}
	}

	fill(t_distance.begin(), t_distance.end(), 0);
	fill(visited.begin(), visited.end(), false);

	BFS(max);

	sort(t_distance.begin(), t_distance.end());

	cout << t_distance.at(n);

	return 0;
}


void BFS(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (pair<int, int> i : v.at(now)) {
			if (!visited.at(i.first)) {
				visited.at(i.first) = true;
				q.push(i.first);
				t_distance[i.first] = t_distance[now] + i.second;
			}
		}
	}
}