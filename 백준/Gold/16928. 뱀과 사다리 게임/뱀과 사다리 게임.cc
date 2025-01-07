#include <iostream>
#include <queue>

using namespace std;

static int board[101];
static bool visited[101];
static int ladder[101];
static int snake[101];

void BFS(int node);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        int start, end;
        cin >> start >> end;
        ladder[start] = end;
    }
    
    for(int i=0;i<m;i++){
        int start, end;
        cin >> start >> end;
        snake[start] = end;
    }
    
    BFS(1);
    
    cout << board[100] << endl;
    
    /*
    for(int i=1;i<=100;i++){
        if(i%10 == 0) cout << endl;
        cout << board[i] << " ";
    }
    */
    
}


void BFS(int node) {
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        

        for(int i=1;i<=6;i++){
            int next = now + i;
            
            if(next < 101 && !visited[next]) {
                board[next] = board[now] + 1;
                
                if(next == 100){
                    return;
                }
                
                visited[next] = true;
                if(ladder[next]){
                    q.push(ladder[next]);
                    
                    if(visited[ladder[next]]) continue;
                    visited[ladder[next]] = true;
                    board[ladder[next]] = board[now] + 1;
                }else if(snake[next]) {
                    q.push(snake[next]);
                    
                    if(visited[snake[next]]) continue;
                    visited[snake[next]] = true;
                    board[snake[next]] = board[now] + 1;
                } else {
                    q.push(next);
                }
            }
            
        }
    }
}
