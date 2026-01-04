#include <iostream>
#include <queue>

using namespace std;

const int MAX_LENGTH = 200;

int N, ans = MAX_LENGTH;
int map[100][100];
int island[100][100];
int vis[100][100];

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

void check_num(int fr, int fc, int num);
void go(int fr, int fc, int num);

int main() {
    cin >> N;

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> map[i][j];
        }
    }

    int num = 1;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            // 섬 번호 마킹하기
            if (map[i][j] == 1 && island[i][j] == 0) {
                check_num(i, j, num);
                // 섬 번호 증가
                num++;
            }
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            // 지금 위치가 육지라면
            if (map[i][j] == 1) {
                // 근처에 바다가 있다면 다른 섬 찾으러 가기
                for (int d=0;d<4;d++) {
                    int fi = i + dr[d];
                    int fj = j + dc[d];

                    if (fi < 0 || fi >= N || fj < 0 || fj >= N)continue;
                    if (map[fi][fj] == 0) {
                        fill(vis[0], vis[100], 0);
                        go(i, j, island[i][j]);
                        break;
                    }
                }
            }
        }
    }

    cout << ans - 2;
}

void go(int fr, int fc, int num) {
    queue<pair<int, int >> q;
    q.push({fr, fc});

    vis[fr][fc] = 1;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (vis[r][c] > ans) return;

        if (island[r][c] != 0 && island[r][c] != num) {
            if (ans > vis[r][c]) ans = vis[r][c];
            return;
        }

        for (int d=0;d<4;d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (island[nr][nc] == num || vis[nr][nc]) continue;

            vis[nr][nc] = vis[r][c] + 1;
            q.push({nr, nc});
        }
    }
}

void check_num(int fr, int fc, int num) {
    queue<pair<int, int>> q;
    q.push({fr, fc});
    island[fr][fc] = num;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d=0;d<4;d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (island[nr][nc] || map[nr][nc] == 0) continue;

            island[nr][nc] = num;
            q.push({nr ,nc});
        }
    }
}