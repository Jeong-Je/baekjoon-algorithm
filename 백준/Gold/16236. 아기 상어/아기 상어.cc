#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

static int map[20][20];
static bool visited[20][20];
static bool found;

int N, shark_size, start_i, start_j, total_time;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void BFS(int i, int j);

int main() {
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            
            if(map[i][j] == 9) {
                start_i = i;
                start_j = j;
                
                map[i][j] = 0;
            }
        }
    }
    
    shark_size = 2;
    int eat_cnt = 0;
    
    do {
        found = false;
        fill(visited[0], visited[N], false);
        
        if(eat_cnt == shark_size) {
            shark_size++;
            eat_cnt = 0;
        }
        
        BFS(start_i, start_j);
        
        map[start_i][start_j] = 0;
        
        eat_cnt++;
        
    } while(found);
    
    
    cout << total_time;
}


void BFS(int i, int j) {
    visited[i][j] = true;

    queue<tuple<int, int, int>> q;
    q.push({i, j, 0});

    int temp = -1;
    found = false;

    while (!q.empty()) {
        auto [now_i, now_j, cnt] = q.front();
        q.pop();

        // 이미 먹을 물고기를 찾았고, 그보다 더 먼 곳은 볼 필요 없음
        if (temp != -1 && cnt > temp) break;

        if (map[now_i][now_j] > 0 && map[now_i][now_j] < shark_size) {
            if (!found || now_i < start_i || (now_i == start_i && now_j < start_j)) {
                start_i = now_i;
                start_j = now_j;
                temp = cnt;
                found = true;
            }
        }

        for (int d = 0; d < 4; d++) {
            int next_i = now_i + di[d];
            int next_j = now_j + dj[d];

            if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < N && !visited[next_i][next_j]) {
                if (map[next_i][next_j] <= shark_size) {
                    visited[next_i][next_j] = true;
                    q.push({next_i, next_j, cnt + 1});
                }
            }
        }
    }

    if (found) {
        total_time += temp;
    }
}
