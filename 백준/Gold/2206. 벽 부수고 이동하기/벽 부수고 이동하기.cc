// 2206 벽 부수고 이동하기 (https://www.acmicpc.net/problem/2206)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N, M;
static int board[1001][1001];
static int visited[1001][1001][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS();

int main(){
    cin >> N >> M;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%1d", &board[i][j]);
        }
    }
    
    cout << BFS();
}

int BFS(){
    visited[1][1][0] = true;
    
    queue<pair<pair<int, int>, int>> que; // {x,y좌표}  {벽뚫 유무}
    que.push({ {1, 1}, 0});
    
    while(!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int wall = que.front().second;
        que.pop();
        
        if(x==N && y==M) return visited[x][y][wall];
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx > 0 && nx <= N && ny > 0 && ny <= M) {
                if(!board[nx][ny] && !visited[nx][ny][wall]) {
                    visited[nx][ny][wall] = visited[x][y][wall] + 1;
                    que.push({ {nx, ny}, wall });
                }
                
                if(board[nx][ny] && !wall) {
                    visited[nx][ny][1] = visited[x][y][wall] + 1;
                    que.push({ {nx, ny}, 1});
                }
            }
        }
    }
    
    return -1;
}