#include <iostream>
#include <queue>

using namespace std;

int map[8][8];
int map_copy[8][8];
bool visited[8][8];

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int N, M, ans;

void bfs(int i, int j, int map[8][8]);
void spread_start();

int main()
{
    cin >> N >> M;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> map[i][j];
        }
    }
    
    for(int i=0;i<N*M;i++)
    {
        int x1 = i / M;
        int y1 = i % M;
        if(map[x1][y1] != 0) continue;
        
        map[x1][y1] = 1;
        
        for(int j=i+1;j<N*M;j++)
        {
            int x2 = j / M;
            int y2 = j % M;
            
            if(map[x2][y2] != 0) continue;
        
            map[x2][y2] = 1;
            
            for(int k=j+1;k<N*M;k++)
            {
                int x3 = k / M;
                int y3 = k % M;
                
                if(map[x3][y3] != 0) continue;
            
                map[x3][y3] = 1;
                
                spread_start();
                
                map[x3][y3] = 0;
            }
            map[x2][y2] = 0;
        }
        map[x1][y1] = 0;
    }
    
    
    cout << ans;
}

void spread_start()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++){
            map_copy[i][j] = map[i][j];
            visited[i][j] = false;
        }
    }
    
    // 바이러스 퍼뜨리기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 2 && !visited[i][j]) {
                bfs(i, j, map_copy);
            }
        }
    }
    
    // 안전 구역 카운팅
    int count = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(map_copy[i][j] == 0) count++;
        }
    }
    
    ans = ans > count ? ans : count;
    

}

void bfs(int i, int j, int map[8][8])
{
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push({i, j});
    
    
    while(!q.empty())
    {
        auto [now_i, now_j] = q.front();
        q.pop();
        
        for(int d=0;d<4;d++)
        {
            int next_i = now_i + di[d];
            int next_j = now_j + dj[d];
            
            if(next_i < 0 || next_i >= N || next_j < 0 || next_j >= M) continue;
            if(visited[next_i][next_j] == true) continue;
            if(map[next_i][next_j] != 0) continue;
            
            
            map[next_i][next_j] = 2;
            visited[next_i][next_j] = true;
            
            q.push({next_i, next_j});
        }
    }
}