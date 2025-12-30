#include <iostream>
#include <queue>

using namespace  std;

int R, C;

queue<pair<int, int>> fire_que;
queue<pair<int, int>> jihu_que;

char map[1000][1000];
int visited[1000][1000];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int start_r, start_c;

void bfs(int r, int c);

int main() {
    cin >> R >> C;

    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            char c;
            cin >> c;

            if (c=='J') {
                start_r = i;
                start_c = j;
                map[i][j] = '.';
            } else if (c == 'F') {
                fire_que.push({i, j});
                map[i][j] = 'F';
            } else if (c == '#') {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }

    bfs(start_r, start_c);
}

void bfs(int r, int c) {
    jihu_que.push({r, c});
    visited[r][c] = 1;

    while (!jihu_que.empty()) {
        // 1. 불 먼저 확산 !
        int fire_size = fire_que.size();
        for (int i=0;i<fire_size;i++) {
            auto [now_i, now_j] = fire_que.front();
            fire_que.pop();

            for (int d=0;d<4;d++) {
                int next_i = now_i + dr[d];
                int next_j = now_j + dc[d];

                if (next_i < 0 || next_i >= R || next_j < 0 || next_j >= C) continue;
                if (map[next_i][next_j] != '.') continue;

                map[next_i][next_j] = 'F';
                fire_que.push({next_i, next_j});
            }
        }

        // 2. 지훈 이동 !
        int jihu_size = jihu_que.size();
        for (int i=0;i<jihu_size;i++) {
            auto [now_i, now_j] = jihu_que.front();
            jihu_que.pop();

            for (int d=0;d<4;d++) {
                int next_i = now_i + dr[d];
                int next_j = now_j + dc[d];

                // 탈출 성공 !
                if (next_i < 0 || next_i >= R || next_j < 0 || next_j >= C) {
                    cout << visited[now_i][now_j];
                    return;
                }

                // 이미 방문했거나 길이 아니면 이동 불가
                if (visited[next_i][next_j] || map[next_i][next_j] != '.') continue;

                visited[next_i][next_j] = visited[now_i][now_j] + 1;
                jihu_que.push({next_i, next_j});
            }
        }

    }


    cout << "IMPOSSIBLE";
}