

#include <iostream>
#include <queue>

using namespace std;

int board[301][301];
bool visited[301][301];

int l;
int sx, sy;
int ex, ey;

void BFS(int x,int y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
        cin >> l;
        cin >> sx >> sy;
        cin >> ex >> ey;
        BFS(sx, sy);
    }

    return 0;
}

void BFS(int x,int y){
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x ,y));
    
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        if(now.first ==  ex && now.second == ey) {
            cout << board[now.first][now.second] << "\n";
            fill(board[0], board[301], 0);
            fill(visited[0], visited[301], false);
            return;
        }
        for(int i=0;i<8;i++){
            int next_x, next_y;
            switch(i){
                case 0:
                    next_x = now.first + 1;
                    next_y = now.second + 2;
                    break;
                case 1:
                    next_x = now.first + 2;
                    next_y = now.second + 1;
                    break;
                case 2:
                    next_x = now.first + 2;
                    next_y = now.second - 1;
                    break;
                case 3:
                    next_x = now.first + 1;
                    next_y = now.second - 2;
                    break;
                case 4:
                    next_x = now.first - 1;
                    next_y = now.second - 2;
                    break;
                case 5:
                    next_x = now.first - 2;
                    next_y = now.second - 1;
                    break;
                case 6:
                    next_x = now.first - 2;
                    next_y = now.second + 1;
                    break;
                case 7:
                    next_x = now.first - 1;
                    next_y = now.second + 2;
                    break;
            }
            if(next_x < l && next_y < l && next_x > -1 && next_y > -1){
                if(!visited[next_x][next_y]){
                    visited[next_x][next_y] = true;
                    board[next_x][next_y] = board[now.first][now.second] + 1;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
    }
}