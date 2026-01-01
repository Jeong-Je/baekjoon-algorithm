#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int L,R,C;
int start_x, start_y, start_z;

char map[30][30][30];
int dis[30][30][30];

int dr[6] = {-1, 1, 0, 0, 0, 0};
int dc[6] = {0, 0, -1, 1, 0, 0};
int dl[6] = {0, 0, 0, 0, -1, 1};

void bfs(int r, int c, int l);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> L >> R >> C;


        // 입력의 종료 조건
        if (L == 0 && R == 0 && C == 0) break;

        fill(dis[0][0], dis[30][30], 0);

        for (int i=0;i<L;i++) {
            for (int j=0;j<R;j++) {
                for (int k=0;k<C;k++) {
                    char c;
                    cin >> c;

                    map[j][k][i] = c;

                    if (c == 'S') {
                        start_z = i;
                        start_x = j;
                        start_y = k;
                    }
                }
            }
        }

        bfs(start_x, start_y, start_z);
    }
}

void bfs(int r, int c, int l) {
    queue<tuple<int, int, int>> q;
    q.push({r, c, l});

    dis[r][c][l] = 1;

    while (!q.empty()) {
        auto [now_r, now_c, now_l] = q.front();
        q.pop();

        if (map[now_r][now_c][now_l] == 'E') {
            cout << "Escaped in " << dis[now_r][now_c][now_l] - 1 << " minute(s).\n";
            return;
        }

        for (int d=0;d<6;d++) {
            int next_r = now_r + dr[d];
            int next_c = now_c + dc[d];
            int next_l = now_l + dl[d];

            // index - out
            if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C || next_l < 0 || next_l >= L) continue;
            // is wall
            if (map[next_r][next_c][next_l] == '#') continue;
            // is visted
            if (dis[next_r][next_c][next_l]) continue;

            dis[next_r][next_c][next_l] = dis[now_r][now_c][now_l] + 1;
            q.push({next_r, next_c, next_l});
        }


    }

    cout << "Trapped!\n";
}