#include <iostream>
#include <queue>

using namespace std;

int N, M, start_i, start_j;

char map[1000][1000];
int visited[1000][1000];
int visited_f[1000][1000];

int dr[4] = { -1,1,0,0};
int dc[4] = {0, 0, -1, 1};


queue<pair<int, int>> q;

void bfs(bool is_fire);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for(int t=0; t<T; t++) {
		cin >> M >> N;

		fill(visited[0], visited[1000], false);
		fill(visited_f[0], visited_f[1000], false);

		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				char c;
				cin >> c;

				map[i][j] = c;

				if(c == '@') {
					start_i = i;
					start_j = j;
					map[i][j] = '.';

					visited[i][j] = 1;
				} else if(c == '*') {
					visited_f[i][j] = 1;
					q.push({i, j});
				}
			}
		}

		bfs(true);

		q.push({start_i, start_j});
		bfs(false);
	}
}


void bfs(bool is_fire) {
	while(!q.empty()) {
		auto [now_r, now_c] = q.front();
		q.pop();

		for(int d=0; d<4; d++) {
			int next_r = now_r +dr[d];
			int next_c = now_c+ dc[d];

			if(is_fire) {
				if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) continue;
				if(map[next_r][next_c] == '#' || map[next_r][next_c] == '*') continue;
				if(visited_f[next_r][next_c]) continue;

				visited_f[next_r][next_c] = visited_f[now_r][now_c] + 1;

				q.push({next_r, next_c});
			} else {
				if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) {
					cout << visited[now_r][now_c] << '\n';
					return;
				}

				if(visited[next_r][next_c]) continue;
				if(map[next_r][next_c] == '#' || map[next_r][next_c] == '*') continue;

				if(visited_f[next_r][next_c] != 0 && visited[now_r][now_c] + 1 >= visited_f[next_r][next_c]) continue;

				visited[next_r][next_c] = visited[now_r][now_c]  +1;

				q.push({next_r, next_c});
			}
		}
	}

	if(is_fire == false) {
		cout << "IMPOSSIBLE\n";
	}
}