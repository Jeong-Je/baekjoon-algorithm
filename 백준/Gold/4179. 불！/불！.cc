#include <iostream>
#include <queue>

using namespace std;

static int map[1001][1001];
static int visited[1001][1001];
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

int R, C;

void bfs(int j_i, int j_j);

int main()
{
   cin >> R >> C;
   
   int start_i, start_j;
   int fire_i, fire_j;
   for(int i=0;i<R;i++)
   {
       for(int j=0;j<C;j++)
       {
           char c;
           cin >> c;
           if(c == '#') map[i][j] = 1;
           else if(c == '.') map[i][j] = 0;
           else if(c == 'J') {start_i = i; start_j = j;} 
           else {q2.push({i, j}); map[i][j] = 2;}
       }
   }
   
   
   bfs(start_i, start_j);
}

void bfs(int j_i, int j_j)
{
    visited[j_i][j_j] = 1;
    
    q1.push({j_i, j_j});
    
while(!q1.empty())
{
    // 1. 불 확산
    int q2_size = q2.size();
    for(int i=0;i<q2_size;i++) {
        auto [f_now_i, f_now_j] = q2.front();
        q2.pop();
        for(int d=0;d<4;d++) {
            int f_next_i = f_now_i + di[d];
            int f_next_j = f_now_j + dj[d];
            if(f_next_i < 0 || f_next_i >= R || f_next_j < 0 || f_next_j >= C) continue;
            if(map[f_next_i][f_next_j] == 0) {
                map[f_next_i][f_next_j] = 2;
                q2.push({f_next_i, f_next_j});
            }
        }
    }

    // 2. 지훈 이동
    int q1_size = q1.size();
    for(int i=0;i<q1_size;i++) {
        auto [j_now_i, j_now_j] = q1.front();
        q1.pop();

        for(int d=0; d<4; d++) {
            int j_next_i = j_now_i + di[d];
            int j_next_j = j_now_j + dj[d];

            // 탈출 성공
            if(j_next_i < 0 || j_next_i >= R || j_next_j < 0 || j_next_j >= C) {
                cout << visited[j_now_i][j_now_j];
                return;
            }

            if(visited[j_next_i][j_next_j]) continue;
            if(map[j_next_i][j_next_j] != 0) continue; // 벽 or 불이면 못 감

            visited[j_next_i][j_next_j] = visited[j_now_i][j_now_j] + 1;
            q1.push({j_next_i, j_next_j});
        }
    }
}

    
    
    cout << "IMPOSSIBLE";
}