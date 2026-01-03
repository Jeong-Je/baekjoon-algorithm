#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, ans;
int map[300][300];
int vis[300][300];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

queue<tuple<int, int, int>> qt;

void bfs(int fr, int fc);

int main() {
    cin >> N >> M;

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }


    while (true) {
        ans++;
        bool find = false;

        // 빙하 찾기 위한 반복문
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                // 빙하 발견
                if (map[i][j] != 0) {
                    find = true;

                    // 상하좌우 물 개수 구하기
                    int cnt = 0;
                    for (int d=0;d<4;d++) {
                        int nr = i + dr[d];
                        int nc = j + dc[d];

                        if (map[nr][nc] == 0) cnt++;
                    }

                    // 주변에 물이 있다면 정보 저장하기
                    if (cnt != 0) {
                        qt.push({i, j, cnt});
                    }
                }
            }
        }

        // 빙하가 전부 녹았다면
        if (find == false) {
            cout << 0;
            break;
        }

        // 빙하 녹이기
        while (!qt.empty()) {
            auto [r, c, cnt] = qt.front();
            qt.pop();

            map[r][c] -= cnt;

            if (map[r][c] < 0) map[r][c] = 0;
        }

        // 빙하 분리 판단하기
        fill(vis[0], vis[N], false);
        int cnt = 0;
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                // 빙하 발견
                if (map[i][j] != 0 && !vis[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        // 빙하가 2개 이상으로 분리되었으면 끝
        if (cnt >= 2) {
            cout << ans;
            break;
        }
    }
}

void bfs(int fr, int fc) {
    queue<pair<int, int>> q;
    q.push({fr, fc});

    vis[fr][fc] = true;

    while (!q.empty()) {
        auto [r , c] = q.front();
        q.pop();

        for (int d=0;d<4;d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (vis[nr][nc] || map[nr][nc] == 0) continue;

            vis[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}