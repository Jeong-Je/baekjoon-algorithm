#include <iostream>
#include <queue>
#include <vector>

using namespace std;



static int m, n, h;

static int box[101][101][101];

class Point {
public:
	int x;
	int y;
	int z;
};


static int days[101][101][101];
static bool visited[101][101][101];
static queue<Point> q;

int my[] = { 0, 0, 1, -1, 0, 0 };
int mx[] = { 1, -1, 0, 0, 0, 0 };
int mz[] = { 0, 0, 0, 0, 1, -1 };


void BFS() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int ny = y + my[i];
			int nx = x + mx[i];
			int nz = z + mz[i];
			if (ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz>=h)continue;
			if (box[nz][ny][nx] == 0 && visited[nz][ny][nx] == 0) {
				visited[nz][ny][nx] = 1;
				box[nz][ny][nx] = 1;
				Point p;
				p.x = nx;
				p.y = ny;
				p.z = nz;
				q.push(p);
				days[nz][ny][nx] = days[z][y][x] + 1;
			}
		}
;	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> box[k][i][j];
				if (box[k][i][j] == 1) {
					visited[k][i][j] = 1;
					Point p;
					p.y = i;
					p.x = j;
					p.z = k;
					q.push(p);
				}
			}
		}
	}

	BFS();
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[k][i][j] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}
	}

	int result = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (result < days[k][i][j]) {
					result = days[k][i][j];
				}
			}
		}
	}

	cout << result;
	
	return 0;
}