#include <iostream>

using namespace std;

int N, M, r, c, d, count = 0;

int map[50][50];
bool visited[50][50];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void move(int r, int c, int d);

int main(){
    cin >> N >> M >> r >> c >> d;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    
    move(r, c, d);
}


void move(int r, int c, int d){
    if(visited[r][c] == false){
        visited[r][c] = true;
        count++;
    }
    
    for(int i=0;i<4;i++){
        int next_d = (d + 3 - i) % 4;
        int next_r = r + dx[next_d];
        int next_c = c + dy[next_d];
        
        if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M || map[next_r][next_c] == 1)
        {
            continue;
        }
        
        if (map[next_r][next_c] == 0 && visited[next_r][next_c] == false)
        {
            move(next_r, next_c, next_d);
        }
    }
    
    int back_r, back_c;
    if(d == 0){
        back_r = r + 1;
        back_c = c;
    } else if(d == 1) {
        back_r = r;
        back_c = c - 1;
    } else if(d == 2) {
        back_r = r - 1;
        back_c = c;
    } else if(d == 3) {
        back_r = r;
        back_c = c + 1;
    }
    
    if (back_r >= 0 && back_r <= N || back_c >= 0 || back_c <= M)
    {
        if (map[back_r][back_c] == 0)
        {
            move(back_r, back_c, d);
        }
        else
        {
            cout << count;
            exit(0);
        }
    }
}