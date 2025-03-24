 #include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N, K;
static bool visited[100001];

void BFS(int start);

int main() {
    cin >> N >> K;
    BFS(N);
}

void BFS(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // {걸린 시간, 현재 위치}

    while (!pq.empty()) {
        int cnt = pq.top().first;  // 현재까지 걸린 시간
        int now = pq.top().second; // 현재 위치
        pq.pop();

        // 방문 체크는 pop한 후에 해야 더 빠른 경로로 올 수 있음
        if (visited[now]) continue;
        visited[now] = true;

        // 동생을 찾으면 출력 후 종료
        if (now == K) {
            cout << cnt;
            return;
        }

        // 3가지 이동 방식
        int next_positions[3] = {now - 1, now + 1, now * 2};

        for (int i = 0; i < 3; i++) {
            int next_x = next_positions[i];

            if (next_x >= 0 && next_x <= 100000 && !visited[next_x]) {
                if (i == 2) { // 순간이동은 0초 걸림
                    pq.push({cnt, next_x});
                } else { // 걷기는 1초 걸림
                    pq.push({cnt + 1, next_x});
                }
            }
        }
    }
}
