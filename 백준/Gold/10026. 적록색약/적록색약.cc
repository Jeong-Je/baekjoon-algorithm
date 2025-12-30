#include <iostream>
#include <queue>

using namespace std;

int N, ans_normal = 0, ans_blindness = 0;

char map[100][100];
bool visited[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(int i, int j);

int main() {
    cin >> N;

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> map[i][j];
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (visited[i][j] == false) {
                bfs(i, j);
                ans_normal++;
            }
        }
    }

    fill(visited[0], visited[100], false);

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (map[i][j] == 'R') {
                map[i][j] = 'G';
            }
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (visited[i][j] == false) {
                bfs(i, j);
                ans_blindness++;
            }
        }
    }

    cout << ans_normal << ' ' << ans_blindness;
}

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});

    visited[i][j] = true;

    while (!q.empty()) {
        auto[now_i, now_j] = q.front();
        q.pop();

        for (int d =0;d<4;d++) {
            int next_i = now_i + dr[d];
            int next_j = now_j + dc[d];

            if (next_i < 0 || next_j >= N || next_j < 0 || next_j >= N) continue;
            if (visited[next_i][next_j]) continue;

            if (map[i][j] == map[next_i][next_j]) {
                visited[next_i][next_j] = true;
                q.push({next_i, next_j});
            }
        }
    }
}