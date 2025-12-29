#include <iostream>
#include <queue>

using namespace std;

int N, M, max_width = 0, cnt = 0;

int map[500][500];
bool visited[500][500];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(int i, int j);
int max(int a, int b);

int main() {
    cin >> N >> M;

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (map[i][j] == 1 && visited[i][j] == false) {
                cnt++;
                bfs(i, j);
            }
        }
    }

    cout << cnt << '\n' << max_width;
}


void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = true;

    int width = 1;
    while (!q.empty()) {
        auto [now_i, now_j] = q.front();
        q.pop();

        for (int d=0;d<4;d++) {
            int next_i = now_i + dr[d];
            int next_j = now_j + dc[d];

            if (next_i < 0 || next_i >= N || next_j < 0 || next_j >= M) continue;
            if (visited[next_i][next_j] == true || map[next_i][next_j] == 0) continue;

            width++;
            visited[next_i][next_j] = true;
            q.push(make_pair(next_i, next_j));
        }
    }

    max_width = max(max_width, width);
}

int max(int a, int b) {
    if (a < b) return b;
    return a;
}