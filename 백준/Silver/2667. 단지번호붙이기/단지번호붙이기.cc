#include <iostream>
#include <queue>

using namespace std;

int N;

int map[25][25];
bool visited[25][25];

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

priority_queue<int, vector<int>, greater<int>> pq;

void bfs(int i, int c);

int main() {

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && visited[i][j] == false)
            {
                bfs(i, j);
            }
        }
    }

    cout << pq.size() << '\n';

    while (!pq.empty())
    {
        cout << pq.top() << '\n';
        pq.pop();
    }
}


void bfs(int i, int j)
{
    int size = 1;
    queue<pair<int, int>> q;
    q.push({ i, j });
    visited[i][j] = true;

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (map[nr][nc] != 1 || visited[nr][nc]) continue;

            size += 1;

            visited[nr][nc] = true;

            q.push({ nr, nc });
        }
    }

    pq.push(size);
}