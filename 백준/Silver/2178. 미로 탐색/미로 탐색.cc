#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N, M;
static int board[101][101];
static bool visited[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int i, int j);

int depth = 0;
int pop_cnt = 0;
int push_cnt = 0;

int main(){
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d", &board[i][j]);
        }
    }
    
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j] && !visited[i][j]){
                BFS(i, j);
            }
        }
    }
    
    cout << board[N-1][M-1];
}

void BFS(int i, int j){
    visited[i][j] = true;
    
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
 
        for(int i=0;i<4;i++){
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];
        
            if(next_x > -1 && next_x < N && next_y > -1 && next_y < M){
                if(board[next_x][next_y] && !visited[next_x][next_y]){
                    q.push(make_pair(next_x, next_y));
                    board[next_x][next_y] = board[now.first][now.second] + 1;
                    visited[next_x][next_y] = true;
                }
            }
        }
    }
}