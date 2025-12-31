#include <iostream>
#include <queue>

using namespace std;

int N, h, ans = 1;
int min_h = 101, max_h = 0;
int map[100][100];
bool vis[100][100];

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void bfs(int r, int c);

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] < min_h) min_h = map[i][j];
			if (map[i][j] > max_h) max_h = map[i][j];
		}
	}

	for (h = min_h; h <= max_h; h++)
	{
		int count = 0;
		fill(vis[0], vis[100], false);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (vis[i][j] == false && map[i][j] > h)
				{
					count++;
					bfs(i, j);
				}
			}
		}
		ans = ans < count ? count : ans;
	}

	cout << ans;
}


void bfs(int r, int c)
{
	queue<pair<int, int>> q;
	q.push({ r, c });

	vis[r][c] = true;

	while (!q.empty())
	{
		auto [r, c] = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N)continue;
			if (vis[nr][nc]) continue;

			if (map[nr][nc] <= h) continue;

			vis[nr][nc] = true;
			q.push({ nr, nc });
		}
	}

}