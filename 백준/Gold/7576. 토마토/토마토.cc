#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static int m, n;

static vector<vector<int>> v(1001, vector<int>(1001));
static vector<vector<bool>> visited(1001, vector<bool>(1001, 0));
static queue<pair<int, int>> q;

static int days[1001][1001];

int my[] = { 0, 0, 1, -1 };
int mx[] = { 1, -1, 0, 0 };


void BFS() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + my[i];
			int nx = x + mx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (v[ny][nx] == 0 && visited[ny][nx] == 0) {
				visited[ny][nx] = 1;
				v[ny][nx] = 1;
				q.push(make_pair(ny, nx));
				days[ny][nx] = days[y][x] + 1;
			}
		}
;	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 1) {
				visited[i][j] = 1;
				q.push(make_pair(i, j));
			}
		}
	}
	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (result < days[i][j]) {
				result = days[i][j];
			}
		}
	}

	cout << result;
	
	return 0;
}