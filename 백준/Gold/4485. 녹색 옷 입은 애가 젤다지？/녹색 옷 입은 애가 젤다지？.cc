#include <iostream>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

int cave[125][125];
int visit[125][125];
int N;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void move(int r, int c);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    int idx = 1;
    while(N != 0) {
        fill(visit[0], visit[125], INT_MAX);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> cave[i][j];
            }
        }
        
        move(0, 0);
        
        cout << "Problem " << idx << ": " << visit[N-1][N-1] << "\n";
        cin >> N;
        idx++;
    }
}

void move(int r, int c) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.push({cave[r][c], r, c});
    
    visit[r][c] = cave[r][c];
    
    while(!q.empty()) {
        auto [cost, now_r, now_c] = q.top();
        q.pop();
        
        for(int d=0;d<4;d++){
            int next_r = now_r + dr[d];
            int next_c = now_c + dc[d];
            
            if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) continue;
            if(visit[next_r][next_c] != INT_MAX) continue;
            
            if(visit[next_r][next_c] > visit[now_r][now_c] + cave[next_r][next_c]) {
                visit[next_r][next_c] = visit[now_r][now_c] + cave[next_r][next_c];
                q.push({visit[next_r][next_c], next_r, next_c});
            }
        }
    }
}