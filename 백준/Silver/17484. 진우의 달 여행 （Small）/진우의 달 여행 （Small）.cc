#include <iostream>
#include <climits>

using namespace std;

int map[6][6];
int N, M, ans = INT_MAX;

void go_to_moon(int, int, int, int);

int dr[3] = {1, 1, 1};
int dc[3] = {-1, 0, 1};

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
    
    for(int i=0;i<M;i++)
    {
        go_to_moon(4, 0, i, map[0][i]);
    }
    
    cout << ans;
}


void go_to_moon(int pre_direction, int row, int column, int sum)
{
    if(row == N - 1) // 목적지 도착 
    {
        if(sum < ans) ans = sum;
        return;
    }
    
    for(int i=0;i<3;i++)
    {
        if(i == pre_direction) continue;
        
        int nr = row + dr[i];
        int nc = column + dc[i];
        
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        go_to_moon(i, nr, nc, sum + map[nr][nc]);
    }
}
    