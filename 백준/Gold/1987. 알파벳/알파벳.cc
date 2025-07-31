#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int R, C, ans = INT_MIN;
    
static char map[20][20];
static bool alpabet_check[26];
static int visited[20][20];

int dr[4] = {-1,1,0,0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c);

int main(){
    cin >> R >> C;
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> map[i][j];
        }
    }
    
    visited[0][0] += 1;
    alpabet_check[map[0][0] - 'A'] = true;
    
    dfs(0, 0);
    
    if(ans == INT_MIN) cout << 1;
    else cout << ans;
}

void dfs(int r, int c) {

    
    for(int d=0;d<4;d++){
        int next_r = r + dr[d];
        int next_c = c + dc[d];
        
        if(next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
        if(visited[next_r][next_c]) continue;
        if(alpabet_check[map[next_r][next_c] - 'A']) continue;
        
        visited[next_r][next_c] = visited[r][c] + 1;
        alpabet_check[map[next_r][next_c] - 'A'] = true;
        
        if(visited[next_r][next_c] > ans) ans = visited[next_r][next_c];
        dfs(next_r, next_c);
        
        visited[next_r][next_c] = 0;
        alpabet_check[map[next_r][next_c] - 'A'] = false;
    }

}
